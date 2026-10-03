	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r4, r0, #0
	ldr r6, _080B1620 @ =0x03002BE0
	ldr r5, [r6]
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080B1650
	movs r2, #0xa0
	lsls r2, r2, #3
	adds r0, r4, r2
	movs r7, #0
	ldrsh r1, [r0, r7]
	lsls r0, r1, #1
	adds r0, r0, r1
	movs r2, #0x2c
	ldrsh r1, [r5, r2]
	adds r0, r0, r1
	lsls r0, r0, #0xe
	lsrs r0, r0, #0x10
	ldr r3, _080B1624 @ =0xFFFF0000
	ldr r2, [sp]
	ands r2, r3
	orrs r2, r0
	str r2, [sp]
	ldr r7, _080B1628 @ =0x00000502
	adds r0, r4, r7
	movs r7, #0
	ldrsh r1, [r0, r7]
	lsls r0, r1, #1
	adds r0, r0, r1
	movs r7, #0x2e
	ldrsh r1, [r5, r7]
	adds r0, r0, r1
	lsls r0, r0, #0xe
	lsrs r0, r0, #0x10
	lsls r0, r0, #0x10
	ldr r1, _080B162C @ =0x0000FFFF
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	ldr r1, _080B1630 @ =0x00000504
	adds r0, r4, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r1, r0, #1
	adds r1, r1, r0
	movs r7, #0x30
	ldrsh r0, [r5, r7]
	adds r1, r1, r0
	lsls r1, r1, #0xe
	lsrs r1, r1, #0x10
	ldr r0, [sp, #4]
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #4]
	movs r0, #0x10
	mov r1, sp
	bl FUN_0823bb7c
	movs r1, #0xc1
	lsls r1, r1, #4
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080B1638
	ldr r0, [r6]
	movs r1, #1
	movs r2, #0
	bl FUN_0807bbb0
	movs r0, #5
	bl PlaySound_082406e0
	ldr r1, _080B1634 @ =FUN_080ada44
	adds r0, r4, #0
	bl EntityCBB0_SetState
	adds r0, r4, #0
	movs r1, #7
	bl FUN_080ad1ec
	b _080B1650
	.align 2, 0
_080B1620: .4byte 0x03002BE0
_080B1624: .4byte 0xFFFF0000
_080B1628: .4byte 0x00000502
_080B162C: .4byte 0x0000FFFF
_080B1630: .4byte 0x00000504
_080B1634: .4byte FUN_080ada44
_080B1638:
	ldr r0, [r6]
	movs r1, #0
	movs r2, #0
	bl FUN_0807bbb0
	ldr r0, _080B1658 @ =0x00000197
	bl PlaySound_082406e0
	adds r0, r4, #0
	movs r1, #6
	bl FUN_080ad1ec
_080B1650:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B1658: .4byte 0x00000197
