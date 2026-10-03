	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	cmp r1, #0
	bne _080BD708
	ldr r1, _080BD6F0 @ =0x00001785
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #8
	bne _080BD6F4
	adds r1, #0x2f
	adds r0, r4, r1
	movs r1, #0
	movs r2, #4
	bl FUN_080b98c0
	b _080BD832
	.align 2, 0
_080BD6F0: .4byte 0x00001785
_080BD6F4:
	ldr r1, _080BD704 @ =0x000017B4
	adds r0, r4, r1
	movs r2, #1
	rsbs r2, r2, #0
	movs r1, #0
	bl FUN_080b98c0
	b _080BD832
	.align 2, 0
_080BD704: .4byte 0x000017B4
_080BD708:
	movs r6, #0
	ldr r1, _080BD750 @ =0x00001788
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #3
	bhi _080BD7A4
	ldr r0, _080BD754 @ =0x0000178A
	adds r7, r4, r0
	ldrb r5, [r7]
	adds r0, r5, #0
	bl GetWeaponID
	cmp r0, #0
	ble _080BD78C
	ldr r1, _080BD758 @ =0x00001785
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #8
	bne _080BD760
	adds r0, r5, #0
	bl FindRegisteredWeaponSlot
	cmp r0, #0
	bge _080BD7CA
	adds r0, r5, #0
	bl FUN_080bce64
	cmp r0, #0
	beq _080BD7CA
	ldr r1, _080BD75C @ =0x00001787
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0x22
	bne _080BD7CA
	movs r6, #5
	b _080BD7CA
	.align 2, 0
_080BD750: .4byte 0x00001788
_080BD754: .4byte 0x0000178A
_080BD758: .4byte 0x00001785
_080BD75C: .4byte 0x00001787
_080BD760:
	ldr r1, _080BD788 @ =0x00001787
	adds r0, r4, r1
	ldrb r0, [r0]
	ldrb r7, [r7]
	cmp r0, r7
	bne _080BD79A
	adds r0, r5, #0
	bl FindRegisteredWeaponSlot
	cmp r0, #0
	bge _080BD7CA
	adds r0, r5, #0
	bl FUN_080bce64
	movs r6, #5
	cmp r0, #0
	bne _080BD7CA
	movs r6, #0
	b _080BD7CA
	.align 2, 0
_080BD788: .4byte 0x00001787
_080BD78C:
	ldr r1, _080BD7A0 @ =0x00001787
	adds r0, r4, r1
	ldrb r0, [r0]
	bl GetWeaponID
	cmp r0, #0
	ble _080BD7CA
_080BD79A:
	movs r6, #1
	b _080BD7CA
	.align 2, 0
_080BD7A0: .4byte 0x00001787
_080BD7A4:
	ldr r0, _080BD7D8 @ =0x00001787
	adds r2, r4, r0
	adds r0, #3
	adds r1, r4, r0
	ldrb r0, [r2]
	ldrb r1, [r1]
	cmp r0, r1
	beq _080BD7C8
	ldr r1, _080BD7DC @ =0x00001785
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #3
	bhi _080BD7CA
	ldrb r0, [r2]
	bl GetWeaponID
	cmp r0, #0
	bne _080BD7CA
_080BD7C8:
	movs r6, #4
_080BD7CA:
	cmp r6, #4
	beq _080BD7E6
	cmp r6, #4
	bgt _080BD7E0
	cmp r6, #1
	beq _080BD810
	b _080BD824
	.align 2, 0
_080BD7D8: .4byte 0x00001787
_080BD7DC: .4byte 0x00001785
_080BD7E0:
	cmp r6, #5
	beq _080BD7FC
	b _080BD824
_080BD7E6:
	ldr r1, _080BD7F8 @ =0x000017B4
	adds r0, r4, r1
	movs r2, #1
	rsbs r2, r2, #0
	movs r1, #7
	bl FUN_080b98c0
	b _080BD832
	.align 2, 0
_080BD7F8: .4byte 0x000017B4
_080BD7FC:
	ldr r1, _080BD80C @ =0x000017B4
	adds r0, r4, r1
	movs r2, #1
	rsbs r2, r2, #0
	movs r1, #6
	bl FUN_080b98c0
	b _080BD832
	.align 2, 0
_080BD80C: .4byte 0x000017B4
_080BD810:
	ldr r1, _080BD820 @ =0x000017B4
	adds r0, r4, r1
	movs r2, #1
	rsbs r2, r2, #0
	movs r1, #3
	bl FUN_080b98c0
	b _080BD832
	.align 2, 0
_080BD820: .4byte 0x000017B4
_080BD824:
	ldr r1, _080BD838 @ =0x000017B4
	adds r0, r4, r1
	movs r2, #1
	rsbs r2, r2, #0
	adds r1, r2, #0
	bl FUN_080b98c0
_080BD832:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080BD838: .4byte 0x000017B4
