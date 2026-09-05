	push {r4, r5, lr}
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	beq _080EF040
	bl FUN_080edda0
	adds r4, r0, #0
	cmp r4, #0
	beq _080EF040
	movs r0, #0x72
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080EF040
	bl VM_GetPC
	cmp r0, #0
	beq _080EF01E
	bl Script_GetValue
	adds r5, r0, #0
	b _080EF020
_080EF01E:
	movs r5, #0
_080EF020:
	bl VM_GetPC
	cmp r0, #0
	beq _080EF030
	bl Script_GetValue
	adds r1, r0, #0
	b _080EF032
_080EF030:
	movs r1, #0
_080EF032:
	movs r2, #0x94
	lsls r2, r2, #2
	adds r0, r4, r2
	strb r5, [r0]
	adds r2, #2
	adds r0, r4, r2
	strb r1, [r0]
_080EF040:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
