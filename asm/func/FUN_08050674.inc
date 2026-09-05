	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0xbc
	adds r1, r4, #0
	adds r1, #0x29
	ldrb r0, [r1]
	cmp r0, #0
	beq _080506B6
	movs r0, #0
	strb r0, [r1]
	ldr r2, _080506A4 @ =gSystemSaveData
	ldr r0, [r2]
	ldr r1, [r0, #0xc]
	adds r0, r4, #0
	adds r0, #0xc8
	ldr r0, [r0]
	adds r1, r1, r0
	ldr r3, _080506A8 @ =0x0000270F
	cmp r1, r3
	ble _080506AC
	adds r1, r3, #0
	b _080506B2
	.align 2, 0
_080506A4: .4byte gSystemSaveData
_080506A8: .4byte 0x0000270F
_080506AC:
	cmp r1, #0
	bge _080506B2
	movs r1, #0
_080506B2:
	ldr r0, [r2]
	str r1, [r0, #0xc]
_080506B6:
	ldr r0, [r4, #0x24]
	cmp r0, #0x3c
	bne _080506F4
	bl FUN_082410bc
	adds r1, r4, #0
	adds r1, #0x36
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _080506E4
	ldr r0, [r5]
	movs r1, #0xe
	bl FUN_0804a2f8
	ldr r0, _080506E0 @ =0x000002AE
	bl PlaySound_082406e0
	b _080506F4
	.align 2, 0
_080506E0: .4byte 0x000002AE
_080506E4:
	ldr r0, [r5]
	movs r1, #0xf
	bl FUN_0804a2f8
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
_080506F4:
	ldr r0, [r4, #0x24]
	cmp r0, #0xb4
	bne _08050748
	adds r0, r4, #0
	adds r0, #0x36
	ldrb r0, [r0]
	cmp r0, #1
	beq _08050716
	adds r1, r4, #0
	adds r1, #0x35
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bls _0805072C
_08050716:
	movs r1, #0xb
	adds r0, r4, #0
	adds r0, #0x28
	movs r2, #0
	strb r1, [r0]
	adds r1, r4, #0
	adds r1, #0x29
	movs r0, #1
	strb r0, [r1]
	str r2, [r4, #0x24]
	b _0805074C
_0805072C:
	ldr r0, [r5]
	movs r1, #0xb
	bl FUN_0804a2f8
	movs r1, #0xa
	adds r0, r4, #0
	adds r0, #0x28
	strb r1, [r0]
	adds r1, r4, #0
	adds r1, #0x29
	movs r0, #1
	strb r0, [r1]
	movs r0, #0
	b _0805074A
_08050748:
	adds r0, #1
_0805074A:
	str r0, [r4, #0x24]
_0805074C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
