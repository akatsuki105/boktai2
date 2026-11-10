	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x20
	adds r6, r0, #0
	ldr r0, [r6, #0x44]
	adds r7, r0, #0
	adds r7, #0x48
	ldr r0, _0818500C @ =0x0000046D
	adds r1, r6, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08185010
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08185012
	.align 2, 0
_0818500C: .4byte 0x0000046D
_08185010:
	movs r0, #0
_08185012:
	cmp r0, #0
	beq _08185032
	adds r0, r6, #0
	movs r1, #5
	bl Enemy_PlayAnim
	movs r1, #0x90
	lsls r1, r1, #3
	adds r0, r6, r1
	ldrh r0, [r0]
	cmp r0, #1
	bne _08185032
	adds r0, r7, #0
	movs r1, #0x30
	bl AuxAnim_SetAnimSpeed
_08185032:
	ldrh r0, [r7, #8]
	cmp r0, #3
	bne _08185044
	ldrh r0, [r7, #0xe]
	cmp r0, #0
	bne _08185044
	ldr r0, _081851A4 @ =0x000001DD
	bl PlaySound_082406e0
_08185044:
	movs r2, #0x90
	lsls r2, r2, #3
	adds r0, r6, r2
	ldrh r0, [r0]
	movs r2, #6
	cmp r0, #1
	bne _08185054
	movs r2, #3
_08185054:
	ldrh r0, [r7, #8]
	adds r1, r0, #0
	cmp r1, #3
	beq _0818505E
	b _08185216
_0818505E:
	ldrh r0, [r7, #0xe]
	cmp r0, r2
	bgt _08185066
	b _08185216
_08185066:
	adds r5, r6, #0
	adds r5, #0xde
	ldrh r1, [r5]
	movs r0, #4
	movs r3, #0
	mov r8, r3
	movs r4, #0
	mov sb, r4
	orrs r0, r1
	ldr r1, _081851A8 @ =0x0000FFF7
	ands r0, r1
	strh r0, [r5]
	movs r0, #0x80
	lsls r0, r0, #4
	ldr r1, _081851AC @ =0x00000474
	adds r4, r6, r1
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	adds r0, r6, #0
	movs r1, #0
	bl Octopus_FindAdjacentTarget
	adds r3, r5, #0
	adds r2, r4, #0
	cmp r0, #0
	bne _0818509E
	b _08185266
_0818509E:
	ldr r3, _081851B0 @ =Octopus_StateHold
	movs r1, #0x24
	ldr r2, _081851B4 @ =0x0000046D
	adds r0, r6, r2
	movs r2, #1
	strb r2, [r0]
	ldr r4, _081851B8 @ =0x0000046B
	adds r0, r6, r4
	mov r4, r8
	strb r4, [r0]
	ldr r4, _081851BC @ =0x00000553
	adds r0, r6, r4
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r6, r3
	mov r4, sb
	strh r4, [r0]
	movs r1, #2
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r6, r3
	mov r4, r8
	strb r4, [r0]
	adds r3, #1
	adds r0, r6, r3
	strb r1, [r0]
	ldr r4, _081851C0 @ =0x0000046A
	adds r0, r6, r4
	strb r2, [r0]
	ldr r1, _081851C4 @ =0x00000484
	adds r0, r6, r1
	mov r3, sb
	str r3, [r0]
	adds r4, #2
	adds r0, r6, r4
	strb r2, [r0]
	adds r0, r6, #0
	movs r1, #0x12
	bl Enemy_PlayAnimFlipOnly
	movs r0, #0x15
	add r0, sp
	mov r8, r0
	adds r0, r6, #0
	add r1, sp, #0x14
	mov r2, r8
	bl Enemy_SetAnimFacing
	ldr r3, _081851C8 @ =0x085ADBFC
	mov r2, r8
	ldrb r1, [r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	ldrh r4, [r7, #8]
	adds r0, r0, r4
	lsls r0, r0, #3
	adds r0, r0, r3
	ldrh r0, [r0]
	ldrh r1, [r6, #8]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _081851CC @ =0xFFFF0000
	ldr r2, [sp, #0x18]
	ands r2, r4
	orrs r2, r0
	str r2, [sp, #0x18]
	mov r0, r8
	ldrb r1, [r0]
	lsls r0, r1, #2
	adds r0, r0, r1
	ldrh r1, [r7, #8]
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r3
	ldrh r1, [r0, #2]
	ldrh r0, [r6, #0xa]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	ldr r0, _081851D0 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x18]
	mov r2, r8
	ldrb r1, [r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	ldrh r7, [r7, #8]
	adds r0, r0, r7
	lsls r0, r0, #3
	adds r0, r0, r3
	ldrh r1, [r0, #4]
	ldrh r3, [r6, #0xc]
	adds r1, r1, r3
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	add r5, sp, #0x18
	ldr r0, [r5, #4]
	ands r0, r4
	orrs r0, r1
	str r0, [r5, #4]
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r0, [r0]
	ldrb r1, [r0, #4]
	cmp r1, #3
	bhi _081851D8
	ldr r1, _081851D4 @ =0x03002BE0
	ldrb r0, [r0, #4]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldrb r1, [r2]
	str r1, [sp]
	mov r7, sb
	str r7, [sp, #4]
	str r7, [sp, #8]
	str r7, [sp, #0xc]
	str r7, [sp, #0x10]
	adds r1, r5, #0
	movs r2, #0
	movs r3, #0
	bl Player_HoldGrabbed
	b _081852D2
	.align 2, 0
_081851A4: .4byte 0x000001DD
_081851A8: .4byte 0x0000FFF7
_081851AC: .4byte 0x00000474
_081851B0: .4byte Octopus_StateHold
_081851B4: .4byte 0x0000046D
_081851B8: .4byte 0x0000046B
_081851BC: .4byte 0x00000553
_081851C0: .4byte 0x0000046A
_081851C4: .4byte 0x00000484
_081851C8: .4byte 0x085ADBFC
_081851CC: .4byte 0xFFFF0000
_081851D0: .4byte 0x0000FFFF
_081851D4: .4byte 0x03002BE0
_081851D8:
	cmp r1, #4
	bne _081852D2
	ldr r4, [r0, #0x38]
	movs r1, #0x8e
	lsls r1, r1, #1
	adds r0, r4, r1
	mov r2, sb
	strh r2, [r0]
	adds r0, r4, #0
	bl Enemy_ClearDamage
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r4, r3
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	mov r7, r8
	ldrb r0, [r7]
	str r0, [sp]
	mov r0, sb
	str r0, [sp, #4]
	adds r0, r4, #0
	movs r1, #0
	adds r2, r5, #0
	movs r3, #0
	bl Enemy_OnCrushed
	b _081852D2
_08185216:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi _08185248
	adds r3, r6, #0
	adds r3, #0xde
	ldrh r1, [r3]
	ldr r0, _0818523C @ =0x0000FFFB
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	strh r0, [r3]
	ldr r1, _08185240 @ =0x00000474
	adds r2, r6, r1
	ldr r0, _08185244 @ =0xFFFFF7FF
	ldrh r1, [r2]
	ands r0, r1
	b _08185264
	.align 2, 0
_0818523C: .4byte 0x0000FFFB
_08185240: .4byte 0x00000474
_08185244: .4byte 0xFFFFF7FF
_08185248:
	adds r3, r6, #0
	adds r3, #0xde
	ldrh r1, [r3]
	movs r0, #4
	orrs r0, r1
	ldr r1, _081852E0 @ =0x0000FFF7
	ands r0, r1
	strh r0, [r3]
	movs r0, #0x80
	lsls r0, r0, #4
	ldr r4, _081852E4 @ =0x00000474
	adds r2, r6, r4
	ldrh r1, [r2]
	orrs r0, r1
_08185264:
	strh r0, [r2]
_08185266:
	ldr r7, _081852E8 @ =0x0000046E
	adds r0, r6, r7
	ldrb r0, [r0]
	cmp r0, #0
	beq _081852D2
	ldrh r1, [r3]
	ldr r0, _081852EC @ =0x0000FFFB
	ands r0, r1
	movs r4, #0
	movs r5, #0
	movs r1, #8
	orrs r0, r1
	strh r0, [r3]
	ldr r0, _081852F0 @ =0xFFFFF7FF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	ldr r2, _081852F4 @ =Octopus_StateRetract
	movs r1, #0x26
	ldr r3, _081852F8 @ =0x0000046D
	adds r0, r6, r3
	movs r3, #1
	strb r3, [r0]
	subs r7, #3
	adds r0, r6, r7
	strb r4, [r0]
	adds r7, #0xe8
	adds r0, r6, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r6, r2
	strh r5, [r0]
	movs r1, #2
	movs r2, #3
	subs r7, #0xeb
	adds r0, r6, r7
	strb r4, [r0]
	ldr r4, _081852FC @ =0x00000469
	adds r0, r6, r4
	strb r1, [r0]
	adds r7, #2
	adds r0, r6, r7
	strb r2, [r0]
	ldr r1, _08185300 @ =0x00000484
	adds r0, r6, r1
	str r5, [r0]
	ldr r2, _08185304 @ =0x0000046C
	adds r0, r6, r2
	strb r3, [r0]
_081852D2:
	add sp, #0x20
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081852E0: .4byte 0x0000FFF7
_081852E4: .4byte 0x00000474
_081852E8: .4byte 0x0000046E
_081852EC: .4byte 0x0000FFFB
_081852F0: .4byte 0xFFFFF7FF
_081852F4: .4byte Octopus_StateRetract
_081852F8: .4byte 0x0000046D
_081852FC: .4byte 0x00000469
_08185300: .4byte 0x00000484
_08185304: .4byte 0x0000046C
