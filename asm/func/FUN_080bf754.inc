	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r0, #0x43
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080BF76A
	bl VM_GetValue
	adds r5, r0, #0
	b _080BF76C
_080BF76A:
	movs r5, #0
_080BF76C:
	bl CoffinShop_FindCoffinSlot
	bl GetValuableItemID
	adds r7, r0, #0
	movs r0, #0x4f
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080BF7D2
	movs r4, #0
	cmp r4, r5
	bge _080BF7A8
_080BF786:
	bl VM_GetValue
	adds r1, r0, #0
	ldr r2, _080BF7EC @ =0x00000ECC
	adds r0, r6, r2
	adds r2, r0, r4
	strb r1, [r2]
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r7, r0
	bne _080BF7A2
	movs r0, #0xff
	orrs r1, r0
	strb r1, [r2]
_080BF7A2:
	adds r4, #1
	cmp r4, r5
	blt _080BF786
_080BF7A8:
	cmp r4, #0xb
	bgt _080BF7C0
	ldr r0, _080BF7EC @ =0x00000ECC
	adds r2, r6, r0
	movs r3, #0xff
_080BF7B2:
	adds r1, r2, r4
	ldrb r0, [r1]
	orrs r0, r3
	strb r0, [r1]
	adds r4, #1
	cmp r4, #0xb
	ble _080BF7B2
_080BF7C0:
	ldr r2, _080BF7F0 @ =0x00000ED4
	adds r1, r6, r2
	movs r4, #3
_080BF7C6:
	ldrb r0, [r1]
	strb r0, [r1, #4]
	adds r1, #1
	subs r4, #1
	cmp r4, #0
	bge _080BF7C6
_080BF7D2:
	movs r0, #0x69
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080BF7E6
	bl VM_GetPC_Proxy
	ldr r2, _080BF7F4 @ =0x00000EC4
	adds r1, r6, r2
	str r0, [r1]
_080BF7E6:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080BF7EC: .4byte 0x00000ECC
_080BF7F0: .4byte 0x00000ED4
_080BF7F4: .4byte 0x00000EC4
