	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r5, r1, #0
	mov ip, r2
	ldr r6, [sp, #0x1c]
	ldr r1, [sp, #0x20]
	ldr r2, [r4, #0x1c]
	cmp r2, #1
	bne _0807AC94
	movs r7, #0xdf
	lsls r7, r7, #2
	adds r0, r4, r7
	ldrb r0, [r0]
	cmp r0, #0x15
	beq _0807AC9A
_0807AC94:
	movs r0, #1
	rsbs r0, r0, #0
	b _0807AD56
_0807AC9A:
	cmp r1, #0
	ble _0807ACAC
	ldr r7, _0807ACEC @ =0x0000095A
	adds r0, r4, r7
	strh r1, [r0]
	ldr r0, _0807ACF0 @ =0x0000095C
	adds r1, r4, r0
	movs r0, #0x40
	strh r0, [r1]
_0807ACAC:
	cmp r6, #0
	ble _0807ACB8
	movs r1, #0xd8
	lsls r1, r1, #1
	adds r0, r4, r1
	strh r6, [r0]
_0807ACB8:
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [r4, #0x2c]
	str r1, [r4, #0x30]
	adds r0, r3, #0
	adds r0, #0xe0
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	lsls r0, r0, #1
	adds r3, r0, #1
	movs r7, #0xba
	lsls r7, r7, #2
	adds r0, r4, r7
	strb r3, [r0]
	cmp r3, #4
	bls _0807ACF8
	movs r0, #8
	subs r0, r0, r3
	ldr r3, _0807ACF4 @ =0x000002E6
	adds r1, r4, r3
	strb r0, [r1]
	subs r7, #1
	adds r0, r4, r7
	strb r2, [r0]
	b _0807AD06
	.align 2, 0
_0807ACEC: .4byte 0x0000095A
_0807ACF0: .4byte 0x0000095C
_0807ACF4: .4byte 0x000002E6
_0807ACF8:
	ldr r1, _0807AD38 @ =0x000002E6
	adds r0, r4, r1
	strb r3, [r0]
	ldr r3, _0807AD3C @ =0x000002E7
	adds r1, r4, r3
	movs r0, #0
	strb r0, [r1]
_0807AD06:
	movs r7, #0xd6
	lsls r7, r7, #1
	adds r0, r4, r7
	movs r5, #0
	mov r1, ip
	strh r1, [r0]
	ldr r3, _0807AD40 @ =0x000003D2
	adds r1, r4, r3
	movs r0, #1
	strb r0, [r1]
	movs r0, #0xe6
	bl PlaySound_082406e0
	movs r7, #0xfb
	lsls r7, r7, #2
	adds r1, r4, r7
	ldrh r0, [r1]
	cmp r0, #0
	beq _0807AD2E
	strh r5, [r1]
_0807AD2E:
	ldr r0, [sp, #0x24]
	cmp r0, #0
	bgt _0807AD44
	movs r0, #0
	b _0807AD56
	.align 2, 0
_0807AD38: .4byte 0x000002E6
_0807AD3C: .4byte 0x000002E7
_0807AD40: .4byte 0x000003D2
_0807AD44:
	str r5, [sp]
	ldr r0, [sp, #0x28]
	str r0, [sp, #4]
	adds r0, r4, #0
	ldr r1, [sp, #0x24]
	movs r2, #0
	movs r3, #0
	bl FUN_0807e7fc
_0807AD56:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
