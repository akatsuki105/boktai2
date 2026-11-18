	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r4, [r0]
	adds r0, r6, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0819E434
	b _0819E55E
_0819E434:
	movs r1, #0x80
	lsls r1, r1, #1
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0819E448
	b _0819E55E
_0819E448:
	movs r1, #0x10
	ldr r2, _0819E45C @ =0x00000E48
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0819E460
	movs r0, #1
	b _0819E462
	.align 2, 0
_0819E45C: .4byte 0x00000E48
_0819E460:
	movs r0, #0
_0819E462:
	adds r1, r0, #0
	cmp r1, #0
	bne _0819E474
	ldr r2, _0819E470 @ =0x0000024E
	adds r0, r6, r2
	strh r1, [r0]
	b _0819E55E
	.align 2, 0
_0819E470: .4byte 0x0000024E
_0819E474:
	ldr r0, _0819E484 @ =0x0000024E
	adds r1, r6, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _0819E488
	subs r0, #1
	strh r0, [r1]
	b _0819E55E
	.align 2, 0
_0819E484: .4byte 0x0000024E
_0819E488:
	adds r0, r6, #0
	bl Ax_PickRandomPathNode
	mov r7, sp
	adds r0, r6, #0
	adds r0, #0x9c
	ldr r2, [r0, #8]
	ldrh r1, [r2]
	mov r0, sp
	strh r1, [r0]
	ldrh r1, [r2, #2]
	strh r1, [r7, #4]
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	cmp r2, #0
	blt _0819E4C2
	cmp r1, #0
	blt _0819E4C2
	ldr r0, _0819E4C8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0819E4C2
	ldr r0, _0819E4CC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0819E4D0
_0819E4C2:
	movs r4, #0
	b _0819E4DE
	.align 2, 0
_0819E4C8: .4byte 0x030046A8
_0819E4CC: .4byte 0x030046AC
_0819E4D0:
	ldr r0, _0819E4F0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0819E4DE:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0819E4F4
	adds r0, #4
	b _0819E500
	.align 2, 0
_0819E4F0: .4byte 0x030046A4
_0819E4F4:
	ldr r0, _0819E514 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0819E500:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0819E518
	cmp r2, #2
	beq _0819E51C
	b _0819E520
	.align 2, 0
_0819E514: .4byte 0x030046A4
_0819E518:
	ldrb r0, [r7, #4]
	b _0819E51E
_0819E51C:
	ldrb r0, [r7]
_0819E51E:
	subs r1, r1, r0
_0819E520:
	movs r4, #0
	movs r5, #0
	strh r1, [r7, #2]
	adds r0, r6, #0
	mov r1, sp
	bl Ax_BeginCurveTo
	adds r0, r6, #0
	bl Ax_StopChase
	adds r0, r6, #0
	bl Ax_ResumeHover
	movs r1, #2
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r6, r2
	strb r4, [r0]
	adds r2, #1
	adds r0, r6, r2
	strb r4, [r0]
	adds r2, #1
	adds r0, r6, r2
	strb r1, [r0]
	ldr r1, _0819E568 @ =0x00000484
	adds r0, r6, r1
	str r5, [r0]
	adds r2, #2
	adds r1, r6, r2
	movs r0, #1
	strb r0, [r1]
_0819E55E:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0819E568: .4byte 0x00000484
