	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0xee
	ldrh r0, [r5]
	cmp r0, #0
	bne _0807F9FC
	ldr r0, _0807FA68 @ =0x00000303
	bl PlaySound_082406e0
	ldr r0, _0807FA6C @ =0x000001FB
	bl PlaySound_082406e0
_0807F9FC:
	ldr r0, _0807FA70 @ =0x03002BE0
	mov sl, r0
	ldr r0, [r0]
	adds r2, r0, #0
	adds r2, #0x90
	ldr r1, [r2]
	movs r3, #1
	mov r8, r3
	orrs r1, r3
	str r1, [r2]
	ldr r1, _0807FA74 @ =0x0000060C
	adds r0, r0, r1
	bl ParticleShadow_Hide
	ldrh r1, [r5]
	adds r3, r1, #0
	cmp r3, #7
	bhi _0807FA7C
	adds r7, r4, #0
	adds r7, #0x3c
	adds r6, r4, #0
	adds r6, #0x1c
	cmp r3, #0
	bne _0807FA42
	ldr r0, [r4, #0x44]
	movs r1, #4
	orrs r0, r1
	str r0, [r4, #0x44]
	ldr r2, _0807FA78 @ =0x0000018F
	str r3, [sp]
	adds r0, r7, #0
	adds r1, r6, #0
	movs r3, #1
	bl MainSprite_SetAnim
_0807FA42:
	ldr r1, [r4, #0x18]
	ldrh r0, [r5]
	lsls r0, r0, #7
	ldrh r2, [r1, #0x2c]
	subs r2, r2, r0
	adds r1, r4, #0
	adds r1, #0x5c
	strh r2, [r1]
	ldr r0, [r4, #0x18]
	ldrh r2, [r0, #0x30]
	adds r0, r4, #0
	adds r0, #0x60
	strh r2, [r0]
	adds r0, r4, #0
	movs r2, #0x80
	bl FUN_0807f78c
	b _0807FCA6
	.align 2, 0
_0807FA68: .4byte 0x00000303
_0807FA6C: .4byte 0x000001FB
_0807FA70: .4byte 0x03002BE0
_0807FA74: .4byte 0x0000060C
_0807FA78: .4byte 0x0000018F
_0807FA7C:
	cmp r3, #0x17
	bhi _0807FAE0
	adds r7, r4, #0
	adds r7, #0x3c
	adds r6, r4, #0
	adds r6, #0x1c
	cmp r3, #8
	bne _0807FAA6
	ldr r0, [r4, #0x44]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x44]
	ldr r2, _0807FAD4 @ =0x0000018F
	mov r3, r8
	str r3, [sp]
	adds r0, r7, #0
	adds r1, r6, #0
	movs r3, #1
	bl MainSprite_SetAnim
_0807FAA6:
	ldr r2, _0807FAD8 @ =0x03003540
	ldrh r0, [r5]
	lsls r0, r0, #5
	ldr r1, _0807FADC @ =0xFFFFFD00
	adds r0, r0, r1
	ldrh r3, [r2]
	adds r0, r0, r3
	adds r1, r4, #0
	adds r1, #0x5c
	strh r0, [r1]
	ldrh r0, [r5]
	subs r0, #0x10
	lsls r0, r0, #7
	ldrh r2, [r2, #4]
	subs r2, r2, r0
	adds r0, r4, #0
	adds r0, #0x60
	strh r2, [r0]
	adds r0, r4, #0
	movs r2, #0x48
	bl FUN_0807f78c
	b _0807FCA6
	.align 2, 0
_0807FAD4: .4byte 0x0000018F
_0807FAD8: .4byte 0x03003540
_0807FADC: .4byte 0xFFFFFD00
_0807FAE0:
	cmp r3, #0x27
	bhi _0807FB40
	adds r7, r4, #0
	adds r7, #0x3c
	adds r6, r4, #0
	adds r6, #0x1c
	cmp r3, #0x18
	bne _0807FB0A
	ldr r0, [r4, #0x44]
	movs r1, #4
	orrs r0, r1
	str r0, [r4, #0x44]
	movs r2, #0xc8
	lsls r2, r2, #1
	mov r0, r8
	str r0, [sp]
	adds r0, r7, #0
	adds r1, r6, #0
	movs r3, #1
	bl MainSprite_SetAnim
_0807FB0A:
	ldr r3, _0807FB38 @ =0x03003540
	ldrh r0, [r5]
	lsls r0, r0, #5
	ldr r1, _0807FB3C @ =0xFFFFFB00
	adds r0, r0, r1
	ldrh r2, [r3]
	subs r2, r2, r0
	adds r1, r4, #0
	adds r1, #0x5c
	strh r2, [r1]
	ldrh r0, [r5]
	subs r0, #0x20
	lsls r0, r0, #7
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	adds r2, r4, #0
	adds r2, #0x60
	strh r0, [r2]
	adds r0, r4, #0
	movs r2, #0xc8
	bl FUN_0807f78c
	b _0807FCA6
	.align 2, 0
_0807FB38: .4byte 0x03003540
_0807FB3C: .4byte 0xFFFFFB00
_0807FB40:
	cmp r3, #0x37
	bhi _0807FBA4
	adds r7, r4, #0
	adds r7, #0x3c
	adds r6, r4, #0
	adds r6, #0x1c
	cmp r3, #0x28
	bne _0807FB68
	ldr r0, [r4, #0x44]
	movs r1, #4
	orrs r0, r1
	str r0, [r4, #0x44]
	ldr r2, _0807FB98 @ =0x0000018F
	mov r3, r8
	str r3, [sp]
	adds r0, r7, #0
	adds r1, r6, #0
	movs r3, #1
	bl MainSprite_SetAnim
_0807FB68:
	ldr r3, _0807FB9C @ =0x03003540
	ldrh r0, [r5]
	subs r0, #0x30
	lsls r0, r0, #7
	ldrh r2, [r3]
	subs r2, r2, r0
	adds r1, r4, #0
	adds r1, #0x5c
	strh r2, [r1]
	ldrh r0, [r5]
	lsls r0, r0, #5
	ldr r5, _0807FBA0 @ =0xFFFFFB00
	adds r0, r0, r5
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	adds r2, r4, #0
	adds r2, #0x60
	strh r0, [r2]
	adds r0, r4, #0
	movs r2, #9
	bl FUN_0807f78c
	b _0807FCA6
	.align 2, 0
_0807FB98: .4byte 0x0000018F
_0807FB9C: .4byte 0x03003540
_0807FBA0: .4byte 0xFFFFFB00
_0807FBA4:
	cmp r3, #0x47
	bhi _0807FC08
	adds r7, r4, #0
	adds r7, #0x3c
	adds r6, r4, #0
	adds r6, #0x1c
	cmp r3, #0x38
	bne _0807FBD0
	ldr r0, [r4, #0x44]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x44]
	movs r2, #0xc8
	lsls r2, r2, #1
	mov r0, r8
	str r0, [sp]
	adds r0, r7, #0
	adds r1, r6, #0
	movs r3, #1
	bl MainSprite_SetAnim
_0807FBD0:
	ldr r2, _0807FC00 @ =0x03003540
	ldrh r0, [r5]
	subs r0, #0x40
	lsls r0, r0, #7
	ldrh r1, [r2]
	adds r0, r0, r1
	adds r1, r4, #0
	adds r1, #0x5c
	strh r0, [r1]
	ldrh r0, [r5]
	lsls r0, r0, #5
	ldr r3, _0807FC04 @ =0xFFFFF700
	adds r0, r0, r3
	ldrh r2, [r2, #4]
	adds r0, r0, r2
	adds r2, r4, #0
	adds r2, #0x60
	strh r0, [r2]
	adds r0, r4, #0
	movs r2, #0x89
	bl FUN_0807f78c
	b _0807FCA6
	.align 2, 0
_0807FC00: .4byte 0x03003540
_0807FC04: .4byte 0xFFFFF700
_0807FC08:
	movs r0, #3
	ands r0, r1
	movs r1, #0x5c
	adds r1, r1, r4
	mov sb, r1
	cmp r0, #0
	bne _0807FC1E
	adds r0, r4, #0
	movs r2, #0xc0
	bl FUN_0807f78c
_0807FC1E:
	ldrh r0, [r5]
	adds r7, r4, #0
	adds r7, #0x3c
	adds r6, r4, #0
	adds r6, #0x1c
	cmp r0, #0x48
	bne _0807FC46
	ldr r0, [r4, #0x44]
	movs r1, #4
	orrs r0, r1
	str r0, [r4, #0x44]
	movs r2, #0xc8
	lsls r2, r2, #1
	mov r3, r8
	str r3, [sp]
	adds r0, r7, #0
	adds r1, r6, #0
	movs r3, #1
	bl MainSprite_SetAnim
_0807FC46:
	ldrh r0, [r5]
	cmp r0, #0x60
	bne _0807FC66
	ldr r0, [r4, #0x44]
	movs r1, #4
	orrs r0, r1
	str r0, [r4, #0x44]
	movs r2, #0xc9
	lsls r2, r2, #1
	movs r0, #0
	str r0, [sp]
	adds r0, r7, #0
	adds r1, r6, #0
	movs r3, #1
	bl MainSprite_SetAnim
_0807FC66:
	ldr r0, [r4, #0x18]
	ldrh r0, [r0, #0x2c]
	mov r1, sb
	strh r0, [r1]
	ldr r2, [r4, #0x18]
	ldrh r1, [r5]
	movs r0, #0x68
	subs r0, r0, r1
	lsls r0, r0, #5
	ldrh r1, [r2, #0x30]
	subs r1, r1, r0
	adds r0, r4, #0
	adds r0, #0x60
	strh r1, [r0]
	adds r2, r4, #0
	adds r2, #0x5e
	mov r3, sl
	ldr r0, [r3]
	ldrh r5, [r2]
	mov r8, r5
	movs r3, #0
	ldrsh r1, [r2, r3]
	ldrh r3, [r0, #0x2e]
	movs r5, #0x2e
	ldrsh r0, [r0, r5]
	cmp r1, r0
	ble _0807FCA4
	mov r0, r8
	subs r0, #0xa
	strh r0, [r2]
	b _0807FCA6
_0807FCA4:
	strh r3, [r2]
_0807FCA6:
	adds r0, r7, #0
	adds r1, r6, #0
	bl MainSprite_AdvanceAnim
	ldr r0, [r4, #0x18]
	movs r1, #0xd9
	lsls r1, r1, #2
	adds r2, r0, r1
	adds r0, r4, #0
	adds r0, #0xf2
	ldrh r1, [r2]
	adds r3, r0, #0
	ldrh r5, [r3]
	cmp r1, r5
	bls _0807FCDA
	adds r0, r1, #0
	adds r1, r4, #0
	adds r1, #0xf0
	ldrh r1, [r1]
	subs r0, r0, r1
	ldrh r1, [r3]
	cmp r0, r1
	bge _0807FCD8
	strh r1, [r2]
	b _0807FCDA
_0807FCD8:
	strh r0, [r2]
_0807FCDA:
	adds r1, r4, #0
	adds r1, #0xee
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x68
	bls _0807FD06
	subs r1, #0x98
	movs r0, #2
	strb r0, [r1]
	ldr r0, [r4, #0x18]
	ldrh r1, [r3]
	movs r2, #0xd9
	lsls r2, r2, #2
	adds r0, r0, r2
	strh r1, [r0]
	ldr r1, _0807FD18 @ =FUN_0807fd1c
	adds r0, r4, #0
	bl DjangoBerserk_SetState
_0807FD06:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807FD18: .4byte FUN_0807fd1c
