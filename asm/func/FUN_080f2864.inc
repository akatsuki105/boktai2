	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r5, r0, #0
	mov sb, r5
	adds r7, r5, #0
	adds r7, #0x9c
	ldr r0, _080F2888 @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _080F288C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _080F288E
	.align 2, 0
_080F2888: .4byte 0x0000046C
_080F288C:
	movs r0, #0
_080F288E:
	cmp r0, #0
	beq _080F28C2
	movs r1, #0xb2
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r4, [r0]
	movs r3, #2
	ldr r2, _080F295C @ =0x0000046D
	adds r1, r5, r2
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _080F2960 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r5, r3
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
_080F28C2:
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080F28D8
	b _080F2A2E
_080F28D8:
	adds r0, r5, #0
	bl FUN_080f0a0c
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080F28E6
	b _080F2A2E
_080F28E6:
	ldr r3, _080F2960 @ =0x0000046B
	adds r0, r5, r3
	ldrb r0, [r0]
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r3, r5, r1
	cmp r0, #0
	beq _080F28FE
	movs r1, #0x20
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
_080F28FE:
	movs r1, #0x20
	ldr r0, [r3]
	ands r0, r1
	cmp r0, #0
	bne _080F290A
	b _080F2A24
_080F290A:
	ldrb r1, [r7, #3]
	adds r0, r1, #1
	strb r0, [r7, #3]
	lsls r1, r1, #0x18
	ldr r4, [r7, #8]
	ldrh r2, [r4, #4]
	ldr r0, _080F2964 @ =0x00000FFF
	lsrs r1, r1, #0x18
	ands r0, r2
	cmp r1, r0
	bhs _080F2922
	b _080F2A24
_080F2922:
	ldrb r0, [r4, #6]
	lsrs r4, r0, #4
	ldr r0, _080F2968 @ =0x085AD468
	adds r0, r4, r0
	ldrb r0, [r0]
	cmp r0, #1
	bne _080F294C
	movs r1, #0x21
	rsbs r1, r1, #0
	ldr r0, [r3]
	ands r0, r1
	str r0, [r3]
	adds r0, r7, #0
	bl FUN_08234e3c
	adds r0, r5, #0
	bl FUN_080e6204
	ldr r0, [r7, #8]
	ldrb r0, [r0, #6]
	lsrs r4, r0, #4
_080F294C:
	cmp r4, #4
	bne _080F2970
	ldr r2, _080F296C @ =0x00000482
	adds r1, r5, r2
	movs r0, #2
	strh r0, [r1]
	movs r4, #2
	b _080F29F0
	.align 2, 0
_080F295C: .4byte 0x0000046D
_080F2960: .4byte 0x0000046B
_080F2964: .4byte 0x00000FFF
_080F2968: .4byte 0x085AD468
_080F296C: .4byte 0x00000482
_080F2970:
	ldr r3, _080F29B8 @ =0x00000482
	adds r1, r5, r3
	movs r6, #0
	movs r0, #1
	mov r8, r0
	movs r0, #1
	strh r0, [r1]
	cmp r4, #0
	bne _080F29F0
	mov r1, sb
	adds r1, #8
	adds r0, r7, #0
	movs r2, #0x20
	movs r3, #0x20
	bl FUN_08235038
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _080F29C4
	movs r1, #2
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	strb r6, [r0]
	ldr r3, _080F29BC @ =0x00000469
	adds r0, r5, r3
	strb r6, [r0]
	adds r2, #2
	adds r0, r5, r2
	strb r1, [r0]
	adds r3, #0x1b
	adds r0, r5, r3
	str r4, [r0]
	ldr r1, _080F29C0 @ =0x0000046C
	b _080F29E0
	.align 2, 0
_080F29B8: .4byte 0x00000482
_080F29BC: .4byte 0x00000469
_080F29C0: .4byte 0x0000046C
_080F29C4:
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	strb r6, [r0]
	ldr r1, _080F29E8 @ =0x00000469
	adds r0, r5, r1
	strb r6, [r0]
	ldr r2, _080F29EC @ =0x0000046A
	adds r0, r5, r2
	strb r6, [r0]
	adds r3, #0x1c
	adds r0, r5, r3
	str r4, [r0]
	adds r1, #3
_080F29E0:
	adds r0, r5, r1
	mov r2, r8
	strb r2, [r0]
	b _080F2A2E
	.align 2, 0
_080F29E8: .4byte 0x00000469
_080F29EC: .4byte 0x0000046A
_080F29F0:
	ldr r0, _080F2A1C @ =0x085AD468
	adds r0, r4, r0
	ldrb r2, [r0]
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	movs r1, #0
	strb r1, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r2, [r0]
	ldr r2, _080F2A20 @ =0x00000484
	adds r0, r5, r2
	str r1, [r0]
	adds r3, #2
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
	b _080F2A2E
	.align 2, 0
_080F2A1C: .4byte 0x085AD468
_080F2A20: .4byte 0x00000484
_080F2A24:
	ldr r0, _080F2A3C @ =0x00000484
	adds r1, r5, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_080F2A2E:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080F2A3C: .4byte 0x00000484
