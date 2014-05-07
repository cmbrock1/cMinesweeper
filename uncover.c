void
uncover(mb,sb,rows,cols,r,c)
    {
    if(r<0 || r>rows) return;
    if(c<0 || c>cols) return;
    if(sb[r][c] == UNCOVERED) return;
    if(mb[r][c] == MINE) return;

    sb[r][c] = UNCOVERED;
    if(mb[r][c] == 0)
        {
        uncover(mb,sb,rows,cols,r-1,c-1) //upper left
        uncover(mb,sb,rows,cols,r-1,c)   //above
        uncover(mb,sb,rows,cols,r-1,c+1) //upper right
        uncover(mb,sb,rows,cols,r,c-1)   //left middle
        uncover(mb,sb,rows,cols,r,c+1)   //right middle
        uncover(mb,sb,rows,cols,r+1,c-1) //lower left
        uncover(mb,sb,rows,cols,r+1,c)   //below
        uncover(mb,sb,rows,cols,r+1,c+1) //lower right
        }
    return;
    }


