	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov sl, r0
	mov sb, r2
	ldr r0, _082359DC @ =0x030046A4
	ldr r1, [r0]
	ldr r0, [r1, #0x14]
	mov r8, r0
	ldrh r0, [r2]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	ldrh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	cmp r3, #0
	blt _082359D6
	cmp r2, #0
	blt _082359D6
	ldr r0, _082359E0 @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _082359D6
	ldr r0, _082359E4 @ =0x030046AC
	ldr r0, [r0]
	cmp r2, r0
	blo _082359E8
_082359D6:
	movs r4, #0
	b _082359F2
	.align 2, 0
_082359DC: .4byte 0x030046A4
_082359E0: .4byte 0x030046A8
_082359E4: .4byte 0x030046AC
_082359E8:
	lsls r0, r2, #1
	adds r1, #0x24
	adds r1, r1, r0
	ldrh r0, [r1]
	adds r4, r0, r3
_082359F2:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08235A02
	adds r0, #4
	b _08235A0E
_08235A02:
	ldr r0, _08235A1C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08235A0E:
	ldrh r0, [r0, #2]
	movs r1, #2
	ands r0, r1
	cmp r0, #0
	beq _08235A24
	b _08235A72
	.align 2, 0
_08235A1C: .4byte 0x030046A4
_08235A20:
	movs r0, #1
	b _08235A74
_08235A24:
	movs r7, #0
	mov r1, r8
	ldrh r1, [r1]
	cmp r7, r1
	bge _08235A72
_08235A2E:
	lsls r1, r7, #2
	mov r0, r8
	adds r0, #4
	adds r0, r0, r1
	ldr r0, [r0]
	mov r2, r8
	adds r5, r2, r0
	ldr r0, [r5, #8]
	adds r6, r5, r0
	movs r4, #0
	ldrh r0, [r5]
	cmp r4, r0
	bge _08235A68
_08235A48:
	adds r0, r6, #0
	mov r1, sb
	adds r2, r4, #0
	bl FUN_08235924
	cmp r0, #0
	beq _08235A60
	mov r1, sl
	ldrh r1, [r1, #4]
	cmp r7, r1
	beq _08235A20
	b _08235A72
_08235A60:
	adds r4, #1
	ldrh r2, [r5]
	cmp r4, r2
	blt _08235A48
_08235A68:
	adds r7, #1
	mov r0, r8
	ldrh r0, [r0]
	cmp r7, r0
	blt _08235A2E
_08235A72:
	movs r0, #0
_08235A74:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
