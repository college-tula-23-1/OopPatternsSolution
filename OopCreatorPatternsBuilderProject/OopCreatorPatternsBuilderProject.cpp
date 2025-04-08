#include <iostream>
#include <map>

enum class QueryItem
{
    Table,
    Select,
    Where,
    Join,
    OrderBy
};

class Query
{
    std::multimap<QueryItem, std::string> queryItems;
public:
    void AddItem(QueryItem item, std::string itemString)
    {
        queryItems.insert(std::make_pair(item, itemString));
    }

    void Print()
    {
        std::cout << "SELECT ";
        for (auto it = queryItems.begin(); it != queryItems.end(); it++)
        {
            if (it->first == QueryItem::Select)
                std::cout << it->second << " ";
        }
        
        std::cout << "\n\tFROM " << queryItems.find(QueryItem::Table)->second << "\n";

        if(queryItems.contains(QueryItem::Where))
            std::cout << "\tWHERE " << queryItems.find(QueryItem::Where)->second << "\n";
        
        for (auto it = queryItems.begin(); it != queryItems.end(); it++)
        {
            if (it->first == QueryItem::Join)
            {
                std::cout << "\tJOIN " << queryItems.find(QueryItem::Join)->second << "\n";
            }
        }

        for (auto it = queryItems.begin(); it != queryItems.end(); it++)
        {
            if (it->first == QueryItem::OrderBy)
            {
                std::cout << "\tORDER BY " << it->second << "\n";
            }
        }

    }
};

class QueryBuilder
{
    Query* query;
public:
    QueryBuilder()
    {
        query = new Query();
    }

    QueryBuilder* Reset()
    {
        query = new Query();
        return this;
    }

    QueryBuilder* Table(std::string table)
    {
        query->AddItem(QueryItem::Table, table);
        return this;
    }

    QueryBuilder* Select(std::string fields)
    {
        query->AddItem(QueryItem::Select, fields);
        return this;
    }

    QueryBuilder* Where(std::string expresion)
    {
        query->AddItem(QueryItem::Where, expresion);
        return this;
    }

    QueryBuilder* Join(std::string table, std::string expresion)
    {
        query->AddItem(QueryItem::Join, table + " ON " + expresion);
        return this;
    }

    QueryBuilder* OrderBy(std::string field, bool asc = true)
    {
        query->AddItem(QueryItem::OrderBy, (field + (asc ? " ASC" : " DESC")));
        return this;
    }

    Query* Create()
    {
        return query;
    }
};


int main()
{
    QueryBuilder* builder = new QueryBuilder();

    Query* query = builder->Table("Students")
                        ->Select("last_name, first_name")
                        ->Where("YEAR(birth_date) < 2007")
                        ->OrderBy("last_name")
                        ->Create();
    query->Print();
    std::cout << "\n";

    query = builder->Reset()
        ->OrderBy("af.date", false)
        ->Table("Airflights AS af")
        ->Join("Cities AS c", "af.city_id = c.id")
        ->Select("c.title AS city")
        ->OrderBy("c.title")       
        ->Select("af.title, af.date, af.time")

        ->Create();
    query->Print();
    std::cout << "\n";

    query = builder->Reset()->Table("Airports")->Select("*")->Create();
    query->Print();
}
