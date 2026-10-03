	push {r4, r5, r6, lr}
	adds r5, r0, #0
	cmp r1, #0
	bne _08095852
	ldr r1, _08095840 @ =0x00003AEB
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0x15
	bne _08095844
	adds r0, r5, #0
	movs r1, #0
	movs r2, #4
	bl FUN_0808c658
	b _08095964
	.align 2, 0
_08095840: .4byte 0x00003AEB
_08095844:
	movs r2, #1
	rsbs r2, r2, #0
	adds r0, r5, #0
	movs r1, #0
	bl FUN_0808c658
	b _08095964
_08095852:
	movs r1, #0
	movs r2, #0x9e
	lsls r2, r2, #4
	adds r0, r5, r2
	ldr r0, [r0]
	movs r4, #0xd6
	lsls r4, r4, #2
	adds r0, r0, r4
	ldrb r0, [r0]
	cmp r0, #5
	beq _0809591A
	ldr r0, _08095890 @ =0x00003AEE
	adds r4, r5, r0
	ldrb r0, [r4]
	bl GetWeaponID
	cmp r0, #0
	bne _08095898
	ldr r2, _08095894 @ =0x00003AEB
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0xf
	bhi _080958D8
	bl GetWeaponID
	movs r1, #3
	cmp r0, #0
	bne _0809591A
	movs r1, #0
	b _0809591A
	.align 2, 0
_08095890: .4byte 0x00003AEE
_08095894: .4byte 0x00003AEB
_08095898:
	ldr r1, _080958DC @ =0x00003AEB
	adds r0, r5, r1
	ldrb r1, [r0]
	cmp r1, #0xf
	bhi _08095918
	ldrb r0, [r4]
	cmp r0, r1
	bne _08095914
	bl GetWeaponKind
	movs r6, #1
	rsbs r6, r6, #0
	movs r2, #0
	ldr r0, _080958E0 @ =0x030046A0
	ldr r0, [r0]
	ldrb r3, [r4]
	adds r1, r0, #0
	adds r1, #0x60
_080958BC:
	movs r4, #0
	ldrsh r0, [r1, r4]
	cmp r0, r3
	bne _080958C6
	adds r6, r2, #0
_080958C6:
	adds r1, #2
	adds r2, #1
	cmp r2, #3
	ble _080958BC
	cmp r6, #0
	blt _080958E4
	movs r1, #0
	cmp r6, #3
	bne _0809591A
_080958D8:
	movs r1, #4
	b _0809591A
	.align 2, 0
_080958DC: .4byte 0x00003AEB
_080958E0: .4byte 0x030046A0
_080958E4:
	movs r2, #0
	ldr r0, _08095910 @ =0x00003AE8
	adds r3, r5, r0
	ldrb r0, [r3]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _08095908
	adds r1, r3, #0
	movs r3, #1
_080958F8:
	adds r2, #1
	cmp r2, #3
	bgt _08095908
	ldrb r0, [r1]
	asrs r0, r2
	ands r0, r3
	cmp r0, #0
	beq _080958F8
_08095908:
	movs r1, #0
	cmp r2, #3
	bgt _0809591A
	b _08095918
	.align 2, 0
_08095910: .4byte 0x00003AE8
_08095914:
	movs r1, #3
	b _0809591A
_08095918:
	movs r1, #1
_0809591A:
	cmp r1, #3
	beq _0809594A
	cmp r1, #3
	bgt _08095928
	cmp r1, #1
	beq _0809592E
	b _08095958
_08095928:
	cmp r1, #4
	beq _0809593C
	b _08095958
_0809592E:
	movs r2, #1
	rsbs r2, r2, #0
	adds r0, r5, #0
	movs r1, #5
	bl FUN_0808c658
	b _08095964
_0809593C:
	movs r2, #1
	rsbs r2, r2, #0
	adds r0, r5, #0
	movs r1, #2
	bl FUN_0808c658
	b _08095964
_0809594A:
	movs r2, #1
	rsbs r2, r2, #0
	adds r0, r5, #0
	movs r1, #3
	bl FUN_0808c658
	b _08095964
_08095958:
	movs r2, #1
	rsbs r2, r2, #0
	adds r0, r5, #0
	adds r1, r2, #0
	bl FUN_0808c658
_08095964:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
