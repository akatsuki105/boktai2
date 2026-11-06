	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	str r0, [sp, #8]
	movs r0, #0
	mov sl, r0
	ldr r1, [sp, #8]
	adds r1, #0xfd
	mov sb, r1
	ldr r2, [sp, #8]
	mov r8, r2
	adds r7, r2, #0
	adds r6, r2, #0
	adds r6, #0x1c
_081F5632:
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081F5656
	cmp r1, #0
	blt _081F5656
	ldr r0, _081F565C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081F5656
	ldr r0, _081F5660 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081F5664
_081F5656:
	movs r4, #0
	b _081F5672
	.align 2, 0
_081F565C: .4byte 0x030046A8
_081F5660: .4byte 0x030046AC
_081F5664:
	ldr r0, _081F5684 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081F5672:
	adds r5, r6, #0
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081F5688
	adds r0, #4
	b _081F5694
	.align 2, 0
_081F5684: .4byte 0x030046A4
_081F5688:
	ldr r0, _081F56A8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081F5694:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r3, r0, #8
	cmp r2, #1
	beq _081F56AC
	cmp r2, #2
	beq _081F56B0
	b _081F56B4
	.align 2, 0
_081F56A8: .4byte 0x030046A4
_081F56AC:
	ldrb r0, [r5, #4]
	b _081F56B2
_081F56B0:
	ldrb r0, [r5]
_081F56B2:
	subs r3, r3, r0
_081F56B4:
	movs r1, #2
	ldrsh r0, [r6, r1]
	cmp r0, r3
	bge _081F5704
	mov r2, r8
	ldr r1, [r2]
	movs r2, #1
	adds r0, r1, #0
	ands r0, r2
	cmp r0, #0
	bne _081F56F8
	orrs r1, r2
	mov r0, r8
	str r1, [r0]
	ldr r0, [r6]
	ldr r1, [r6, #4]
	str r0, [sp]
	str r1, [sp, #4]
	subs r1, r3, #1
	lsls r1, r1, #0x10
	ldr r2, _081F5700 @ =0x0000FFFF
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	mov r0, sp
	movs r1, #1
	bl Entity081f73ec_SpawnDust
	mov r2, sb
	ldrb r1, [r2]
	movs r0, #2
	orrs r0, r1
	strb r0, [r2]
_081F56F8:
	movs r0, #1
	rsbs r0, r0, #0
	add sl, r0
	b _081F5742
	.align 2, 0
_081F5700: .4byte 0x0000FFFF
_081F5704:
	adds r4, r7, #0
	adds r4, #0xfd
	ldrb r1, [r4]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _081F573E
	ldr r1, [r7]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _081F573E
	movs r0, #2
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r7]
	ldr r0, [r7, #0x1c]
	ldr r1, [r7, #0x20]
	str r0, [sp]
	str r1, [sp, #4]
	mov r0, sp
	strh r3, [r0, #2]
	movs r1, #1
	bl Entity081f73ec_SpawnDust
	ldrb r1, [r4]
	movs r0, #0xfd
	ands r0, r1
	strb r0, [r4]
_081F573E:
	movs r1, #1
	add sl, r1
_081F5742:
	movs r2, #0x92
	lsls r2, r2, #1
	add sb, r2
	add r8, r2
	adds r7, r7, r2
	adds r6, r6, r2
	ldr r1, [sp, #8]
	ldr r2, _081F5764 @ =0x000005B4
	adds r0, r1, r2
	cmp r8, r0
	bgt _081F575A
	b _081F5632
_081F575A:
	mov r0, sl
	cmp r0, #5
	ble _081F5768
	movs r0, #1
	b _081F5778
	.align 2, 0
_081F5764: .4byte 0x000005B4
_081F5768:
	movs r0, #6
	rsbs r0, r0, #0
	cmp sl, r0
	ble _081F5774
	movs r0, #0
	b _081F5778
_081F5774:
	movs r0, #1
	rsbs r0, r0, #0
_081F5778:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
