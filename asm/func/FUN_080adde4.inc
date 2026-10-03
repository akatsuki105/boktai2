	push {lr}
	movs r1, #0xc1
	lsls r1, r1, #4
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0xa
	bhi _080ADE44
	lsls r0, r0, #2
	ldr r1, _080ADDFC @ =_080ADE00
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080ADDFC: .4byte _080ADE00
_080ADE00: @ jump table
	.4byte _080ADE2C @ case 0
	.4byte _080ADE30 @ case 1
	.4byte _080ADE30 @ case 2
	.4byte _080ADE34 @ case 3
	.4byte _080ADE38 @ case 4
	.4byte _080ADE44 @ case 5
	.4byte _080ADE44 @ case 6
	.4byte _080ADE3C @ case 7
	.4byte _080ADE3C @ case 8
	.4byte _080ADE40 @ case 9
	.4byte _080ADE40 @ case 10
_080ADE2C:
	movs r0, #8
	b _080ADE46
_080ADE30:
	movs r0, #6
	b _080ADE46
_080ADE34:
	movs r0, #4
	b _080ADE46
_080ADE38:
	movs r0, #2
	b _080ADE46
_080ADE3C:
	movs r0, #0xa
	b _080ADE46
_080ADE40:
	movs r0, #0xc
	b _080ADE46
_080ADE44:
	movs r0, #0
_080ADE46:
	pop {r1}
	bx r1
	.align 2, 0
