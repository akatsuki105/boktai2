	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	movs r0, #0x49
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080BC91E
	bl VM_GetValue
	adds r5, r0, #0
	b _080BC920
_080BC91E:
	movs r5, #0
_080BC920:
	movs r0, #0x54
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080BC96C
	movs r4, #0
	cmp r4, r5
	bge _080BC942
	ldr r0, _080BC988 @ =0x000012F4
	adds r6, r7, r0
_080BC934:
	bl VM_GetValue
	adds r1, r6, r4
	strb r0, [r1]
	adds r4, #1
	cmp r4, r5
	blt _080BC934
_080BC942:
	cmp r4, #0xb
	bgt _080BC95A
	ldr r0, _080BC988 @ =0x000012F4
	adds r2, r7, r0
	movs r3, #0xff
_080BC94C:
	adds r1, r2, r4
	ldrb r0, [r1]
	orrs r0, r3
	strb r0, [r1]
	adds r4, #1
	cmp r4, #0xb
	ble _080BC94C
_080BC95A:
	ldr r2, _080BC98C @ =0x000012FC
	adds r1, r7, r2
	movs r4, #3
_080BC960:
	ldrb r0, [r1]
	strb r0, [r1, #4]
	adds r1, #1
	subs r4, #1
	cmp r4, #0
	bge _080BC960
_080BC96C:
	movs r0, #0x69
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080BC980
	bl FUN_0823d340
	ldr r2, _080BC990 @ =0x000012E4
	adds r1, r7, r2
	str r0, [r1]
_080BC980:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080BC988: .4byte 0x000012F4
_080BC98C: .4byte 0x000012FC
_080BC990: .4byte 0x000012E4
