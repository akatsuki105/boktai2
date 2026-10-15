	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r5, r0, #0
	movs r0, #0
	mov r8, r0
	ldrh r1, [r5, #0x24]
	cmp r8, r1
	bge _0801951A
	movs r2, #0x54
	adds r2, r2, r5
	mov sl, r2
	movs r0, #0x34
	adds r0, r0, r5
	mov sb, r0
	mov r4, sb
_08019488:
	mov r1, sb
	ldrb r0, [r4]
	cmp r0, #0
	bne _08019498
	adds r0, r5, #0
	bl Entity99CAElem_TryRespawn
	b _0801949E
_08019498:
	adds r0, r5, #0
	bl Entity99CAElem_Update
_0801949E:
	mov r3, sl
	ldrb r6, [r4, #1]
	ldrh r7, [r4, #4]
	ldr r2, _080194C0 @ =0x085B0A08
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	cmp r0, #0
	blt _080194C4
	asrs r1, r0, #0xc
	b _080194CA
	.align 2, 0
_080194C0: .4byte 0x085B0A08
_080194C4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080194CA:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r6, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r7, r0
	cmp r0, #0
	blt _080194E2
	asrs r0, r0, #0xc
	b _080194E8
_080194E2:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080194E8:
	strh r0, [r3, #4]
	ldrh r1, [r4, #2]
	ldrh r0, [r4, #0x22]
	adds r1, r1, r0
	strh r1, [r4, #0x22]
	ldrh r0, [r5, #0x2c]
	ldrh r2, [r4, #0x20]
	adds r0, r0, r2
	strh r0, [r4, #0x20]
	ldrh r0, [r5, #0x2e]
	adds r1, r1, r0
	strh r1, [r4, #0x22]
	ldrh r0, [r5, #0x30]
	ldrh r1, [r4, #0x24]
	adds r0, r0, r1
	strh r0, [r4, #0x24]
	movs r2, #0x30
	add sl, r2
	adds r4, #0x30
	add sb, r2
	movs r0, #1
	add r8, r0
	ldrh r1, [r5, #0x24]
	cmp r8, r1
	blt _08019488
_0801951A:
	ldrh r2, [r5, #0x24]
	mov r8, r2
	cmp r2, #7
	bgt _08019542
	movs r2, #1
	mov r1, r8
	lsls r0, r1, #1
	add r0, r8
	lsls r0, r0, #4
	adds r0, #0x3c
	adds r1, r0, r5
_08019530:
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r1, #0x30
	movs r0, #1
	add r8, r0
	mov r0, r8
	cmp r0, #7
	ble _08019530
_08019542:
	ldr r0, [r5, #0x18]
	adds r0, #1
	str r0, [r5, #0x18]
	ldr r1, [r5, #0x1c]
	cmp r1, #0
	ble _08019562
	cmp r0, r1
	blt _08019562
	adds r0, r5, #0
	bl Entity99CA_HasActiveElem
	cmp r0, #0
	bne _08019562
	adds r0, r5, #0
	bl KillEntity
_08019562:
	movs r0, #0
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
