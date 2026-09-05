	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	mov r8, r0
	ldr r0, _08001D38 @ =0x00000654
	add r0, r8
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	mov sb, r0
	movs r0, #0xcb
	lsls r0, r0, #3
	add r0, r8
	ldrb r2, [r0]
	ldr r0, _08001D3C @ =0x00000659
	add r0, r8
	ldrb r0, [r0]
	adds r0, r2, r0
	str r0, [sp, #4]
	cmp r0, #0xc
	ble _08001CF8
	ldr r1, _08001D40 @ =0x0000065A
	add r1, r8
	movs r0, #0
	strb r0, [r1]
	movs r0, #0xd
	str r0, [sp, #4]
_08001CF8:
	mov r1, sb
	cmp r1, #0x1f
	ble _08001D4C
	adds r4, r2, #0
	mov r2, r8
	adds r2, #0x20
	str r2, [sp, #0xc]
	ldr r3, [sp, #4]
	cmp r4, r3
	bge _08001DF0
_08001D0C:
	ldr r0, _08001D44 @ =0x0000065C
	add r0, r8
	ldrh r0, [r0]
	asrs r0, r4
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08001D2E
	lsls r2, r4, #5
	mov r7, r8
	ldr r0, [r7, #0x28]
	adds r0, r0, r2
	ldr r1, [r7, #0x2c]
	adds r1, r1, r2
	ldr r2, _08001D48 @ =0x04000008
	bl CpuSet
_08001D2E:
	adds r4, #1
	ldr r0, [sp, #4]
	cmp r4, r0
	blt _08001D0C
	b _08001DF0
	.align 2, 0
_08001D38: .4byte 0x00000654
_08001D3C: .4byte 0x00000659
_08001D40: .4byte 0x0000065A
_08001D44: .4byte 0x0000065C
_08001D48: .4byte 0x04000008
_08001D4C:
	movs r0, #0x20
	mov r1, sb
	subs r1, r0, r1
	str r1, [sp]
	adds r4, r2, #0
	mov r2, r8
	adds r2, #0x20
	str r2, [sp, #0xc]
	ldr r3, [sp, #4]
	cmp r4, r3
	bge _08001DF0
	ldr r7, _08001E14 @ =0x0000065C
	add r7, r8
	str r7, [sp, #8]
_08001D68:
	ldr r0, [sp, #8]
	ldrh r1, [r0]
	asrs r1, r4
	movs r0, #1
	ands r1, r0
	adds r2, r4, #1
	str r2, [sp, #0x10]
	cmp r1, #0
	beq _08001DE8
	lsls r1, r4, #5
	mov r3, r8
	ldr r0, [r3, #0x2c]
	adds r0, r0, r1
	str r0, [sp, #0x14]
	ldr r0, [r3, #0x24]
	adds r6, r0, r1
	ldr r0, [r3, #0x28]
	adds r5, r0, r1
	movs r7, #0xf8
	lsls r7, r7, #2
	mov sl, r7
	movs r0, #0xf
	mov ip, r0
_08001D96:
	ldrh r0, [r6]
	ldr r3, _08001E18 @ =0x00007C1F
	ands r3, r0
	mov r4, sl
	ands r4, r0
	ldrh r1, [r5]
	adds r0, r1, #0
	ldr r2, _08001E18 @ =0x00007C1F
	ands r0, r2
	mov r2, sb
	muls r2, r0, r2
	ldr r7, [sp]
	adds r0, r3, #0
	muls r0, r7, r0
	adds r2, r2, r0
	ldr r0, _08001E1C @ =0x000F83E0
	ands r2, r0
	mov r0, sl
	ands r1, r0
	mov r0, sb
	muls r0, r1, r0
	adds r1, r4, #0
	muls r1, r7, r1
	adds r0, r0, r1
	movs r1, #0xf8
	lsls r1, r1, #7
	ands r0, r1
	orrs r2, r0
	lsrs r2, r2, #5
	ldr r1, [sp, #0x14]
	strh r2, [r1]
	adds r1, #2
	str r1, [sp, #0x14]
	adds r6, #2
	adds r5, #2
	movs r2, #1
	rsbs r2, r2, #0
	add ip, r2
	mov r3, ip
	cmp r3, #0
	bge _08001D96
_08001DE8:
	ldr r4, [sp, #0x10]
	ldr r7, [sp, #4]
	cmp r4, r7
	blt _08001D68
_08001DF0:
	movs r0, #0xcb
	lsls r0, r0, #3
	add r0, r8
	mov r1, sp
	ldrb r1, [r1, #4]
	strb r1, [r0]
	movs r0, #1
	ldr r2, [sp, #0xc]
	strb r0, [r2]
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08001E14: .4byte 0x0000065C
_08001E18: .4byte 0x00007C1F
_08001E1C: .4byte 0x000F83E0
