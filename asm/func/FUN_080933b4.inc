	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x20
	adds r7, r0, #0
	adds r6, r1, #0
	ldr r0, _080934C8 @ =0x00003AEE
	adds r4, r7, r0
	ldrb r0, [r4]
	adds r0, #0x11
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #5
	ldr r3, _080934CC @ =0x00000F6C
	adds r2, r7, r3
	adds r2, r2, r1
	ldr r0, [r2]
	movs r1, #1
	mov r8, r1
	orrs r0, r1
	str r0, [r2]
	ldrb r1, [r4]
	add r0, sp, #0x10
	bl FUN_080921e8
	add r5, sp, #0x18
	ldr r2, _080934D0 @ =0x00003AEB
	adds r0, r7, r2
	ldrb r1, [r0]
	adds r0, r5, #0
	bl FUN_080921e8
	ldr r3, _080934D4 @ =0x00003F9C
	adds r0, r7, r3
	ldrb r0, [r0]
	ldrb r1, [r4]
	bl GetItemID
	adds r2, r0, #0
	adds r2, #0x68
	ldrb r1, [r4]
	adds r1, #0x11
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r0, r7, r0
	ldr r4, _080934D8 @ =0x00000F9E
	adds r0, r0, r4
	ldrh r3, [r0]
	add r0, sp, #0x10
	str r0, [sp]
	str r5, [sp, #4]
	movs r0, #0x18
	str r0, [sp, #8]
	movs r0, #0x10
	str r0, [sp, #0xc]
	adds r0, r7, #0
	movs r1, #0
	bl FUN_0808c334
	cmp r6, #0
	bne _080934FC
	ldr r1, _080934DC @ =0x00003FBB
	adds r0, r7, r1
	mov r2, r8
	strb r2, [r0]
	movs r3, #0x9e
	lsls r3, r3, #4
	adds r2, r7, r3
	ldr r0, [r2]
	movs r4, #0xd9
	lsls r4, r4, #2
	adds r0, r0, r4
	ldrh r1, [r0]
	ldr r3, _080934E0 @ =0x00003FA4
	adds r0, r7, r3
	strh r1, [r0]
	ldr r0, [r2]
	adds r4, #4
	adds r0, r0, r4
	ldrh r0, [r0]
	ldr r1, _080934E4 @ =0x00003FA8
	adds r4, r7, r1
	strh r0, [r4]
	ldr r1, [r2]
	ldr r2, _080934E8 @ =0x00000366
	adds r0, r1, r2
	ldrh r2, [r0]
	ldrh r0, [r4]
	muls r0, r2, r0
	ldr r3, _080934EC @ =0x0000036A
	adds r1, r1, r3
	ldrh r1, [r1]
	bl Div
	ldr r2, _080934F0 @ =0x00003FA6
	adds r1, r7, r2
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08093488
	ldrh r0, [r4]
	cmp r0, #0
	beq _08093488
	mov r3, r8
	strh r3, [r1]
_08093488:
	movs r4, #0x9e
	lsls r4, r4, #4
	adds r0, r7, r4
	ldr r1, [r0]
	ldr r2, _080934EC @ =0x0000036A
	adds r0, r1, r2
	ldrh r2, [r0]
	ldr r3, _080934E0 @ =0x00003FA4
	adds r4, r7, r3
	ldrh r0, [r4]
	muls r0, r2, r0
	ldr r2, _080934E8 @ =0x00000366
	adds r1, r1, r2
	ldrh r1, [r1]
	bl Div
	ldr r3, _080934F4 @ =0x00003FAA
	adds r1, r7, r3
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080934BE
	ldrh r0, [r4]
	cmp r0, #0
	beq _080934BE
	movs r0, #1
	strh r0, [r1]
_080934BE:
	ldr r4, _080934F8 @ =0x00003F9D
	adds r1, r7, r4
	movs r0, #0
	strb r0, [r1]
	b _08093548
	.align 2, 0
_080934C8: .4byte 0x00003AEE
_080934CC: .4byte 0x00000F6C
_080934D0: .4byte 0x00003AEB
_080934D4: .4byte 0x00003F9C
_080934D8: .4byte 0x00000F9E
_080934DC: .4byte 0x00003FBB
_080934E0: .4byte 0x00003FA4
_080934E4: .4byte 0x00003FA8
_080934E8: .4byte 0x00000366
_080934EC: .4byte 0x0000036A
_080934F0: .4byte 0x00003FA6
_080934F4: .4byte 0x00003FAA
_080934F8: .4byte 0x00003F9D
_080934FC:
	ldr r0, _08093564 @ =0x00003FBB
	adds r1, r7, r0
	movs r3, #0
	movs r0, #2
	strb r0, [r1]
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r2, r7, r1
	ldr r0, [r2]
	movs r4, #0xd9
	lsls r4, r4, #2
	adds r0, r0, r4
	ldrh r1, [r0]
	ldr r4, _08093568 @ =0x00003FA4
	adds r0, r7, r4
	strh r1, [r0]
	ldr r0, [r2]
	movs r1, #0xda
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r4, #4
	adds r0, r7, r4
	strh r1, [r0]
	ldr r1, _0809356C @ =0x00003FA6
	adds r0, r7, r1
	strh r3, [r0]
	ldr r0, [r2]
	ldr r2, _08093570 @ =0x0000036A
	adds r0, r0, r2
	ldrh r1, [r0]
	ldr r3, _08093574 @ =0x00003FAA
	adds r0, r7, r3
	strh r1, [r0]
	subs r4, #0xb
	adds r0, r7, r4
	mov r1, r8
	strb r1, [r0]
_08093548:
	ldr r0, _08093578 @ =0x0000038A
	bl PlaySound_082406e0
	ldr r1, _0809357C @ =FUN_08093580
	adds r0, r7, #0
	movs r2, #1
	bl FUN_0808a354
	add sp, #0x20
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08093564: .4byte 0x00003FBB
_08093568: .4byte 0x00003FA4
_0809356C: .4byte 0x00003FA6
_08093570: .4byte 0x0000036A
_08093574: .4byte 0x00003FAA
_08093578: .4byte 0x0000038A
_0809357C: .4byte FUN_08093580
