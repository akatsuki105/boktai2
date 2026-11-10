	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x38
	str r0, [sp, #0x18]
	ldr r0, _0820DA98 @ =0x0000CB05
	ldr r1, _0820DA9C @ =0x00005EBF
	bl GetFile
	adds r1, r0, #0
	ldr r2, [sp, #0x18]
	adds r2, #0x4c
	ldm r0!, {r3, r4, r5}
	stm r2!, {r3, r4, r5}
	ldm r0!, {r3, r4, r5}
	stm r2!, {r3, r4, r5}
	ldm r0!, {r3, r4}
	stm r2!, {r3, r4}
	ldr r4, [sp, #0x18]
	adds r4, #0x4c
	adds r0, r4, #0
	bl OpenMainSpriteFile
	add r2, sp, #0x10
	movs r0, #0
	adds r1, r2, #0
	strh r0, [r1]
	strh r0, [r2, #2]
	strh r0, [r2, #4]
	strh r0, [r2, #6]
	mov sl, r0
	str r4, [sp, #0x20]
	ldr r5, [sp, #0x18]
	adds r5, #0x6c
	str r5, [sp, #0x24]
	ldr r0, [sp, #0x18]
	adds r0, #0x48
	str r0, [sp, #0x1c]
	ldr r1, [sp, #0x18]
	adds r1, #0x8e
	str r1, [sp, #0x28]
	ldr r2, [sp, #0x18]
	adds r2, #0xcc
	str r2, [sp, #0x30]
	ldr r3, [sp, #0x18]
	ldr r4, _0820DAA0 @ =0x000005AC
	adds r3, r3, r4
	mov sb, r3
	movs r5, #0
	str r5, [sp, #0x34]
	ldr r0, [sp, #0x18]
	adds r0, #0xb4
	str r0, [sp, #0x2c]
_0820D752:
	ldr r1, [sp, #0x34]
	ldr r2, _0820DAA4 @ =0x0000084C
	adds r0, r1, r2
	ldr r3, [sp, #0x18]
	adds r4, r3, r0
	movs r5, #1
_0820D75E:
	movs r0, #0
	mov r8, r0
	str r0, [sp]
	movs r7, #2
	str r7, [sp, #4]
	movs r6, #0x3c
	str r6, [sp, #8]
	add r1, sp, #0x10
	str r1, [sp, #0xc]
	adds r0, r4, #0
	ldr r1, [sp, #0x20]
	movs r2, #0
	movs r3, #0x10
	bl MainSprite_Add
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0820D75E
	mov r2, r8
	str r2, [sp]
	str r7, [sp, #4]
	str r6, [sp, #8]
	add r3, sp, #0x10
	str r3, [sp, #0xc]
	mov r0, sb
	ldr r1, [sp, #0x20]
	movs r2, #0xa
	movs r3, #0x10
	bl MainSprite_Add
	movs r4, #0x60
	add sb, r4
	ldr r5, [sp, #0x34]
	adds r5, #0xc0
	str r5, [sp, #0x34]
	movs r0, #1
	add sl, r0
	mov r1, sl
	cmp r1, #6
	ble _0820D752
	add r1, sp, #0x10
	adds r0, r1, #0
	mov r2, r8
	strh r2, [r0]
	strh r2, [r1, #2]
	strh r2, [r1, #4]
	strh r2, [r1, #6]
	ldr r7, [sp, #0x20]
	movs r3, #2
	mov sb, r3
	mov r8, r6
	ldr r4, [sp, #0x18]
	ldr r0, _0820DAA8 @ =0x00000E4C
	adds r5, r4, r0
	ldr r1, _0820DAAC @ =0x00000D8C
	adds r4, r4, r1
	add r6, sp, #0x10
	movs r2, #1
	mov sl, r2
_0820D7D6:
	movs r3, #0
	str r3, [sp]
	mov r0, sb
	str r0, [sp, #4]
	mov r1, r8
	str r1, [sp, #8]
	str r6, [sp, #0xc]
	adds r0, r4, #0
	adds r1, r7, #0
	movs r2, #0
	movs r3, #0x10
	bl MainSprite_Add
	movs r2, #0
	str r2, [sp]
	mov r3, sb
	str r3, [sp, #4]
	mov r0, r8
	str r0, [sp, #8]
	str r6, [sp, #0xc]
	adds r0, r5, #0
	adds r1, r7, #0
	movs r3, #0x10
	bl MainSprite_Add
	adds r5, #0x60
	adds r4, #0x60
	movs r1, #1
	rsbs r1, r1, #0
	add sl, r1
	mov r2, sl
	cmp r2, #0
	bge _0820D7D6
	movs r3, #2
	mov sl, r3
	add r1, sp, #0x10
	movs r4, #0
	adds r0, r1, #0
	strh r4, [r0]
	strh r4, [r1, #2]
	strh r4, [r1, #4]
	strh r4, [r1, #6]
	ldr r5, [sp, #0x18]
	ldr r1, _0820DAB0 @ =0x0000102C
	adds r0, r5, r1
	str r4, [sp]
	str r3, [sp, #4]
	movs r5, #0x3c
	str r5, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	ldr r1, [sp, #0x20]
	movs r2, #0x22
	movs r3, #0x10
	bl MainSprite_Add
	ldr r3, [sp, #0x18]
	ldr r1, _0820DAB4 @ =0x0000108C
	adds r0, r3, r1
	str r4, [sp]
	mov r2, sl
	str r2, [sp, #4]
	str r5, [sp, #8]
	add r3, sp, #0x10
	str r3, [sp, #0xc]
	ldr r1, [sp, #0x20]
	movs r2, #0x23
	movs r3, #0x10
	bl MainSprite_Add
	add r4, sp, #0x10
	movs r6, #0
	ldr r0, [sp, #0x18]
	ldr r1, _0820DAB8 @ =0x00000F0C
	adds r5, r0, r1
	movs r2, #0x20
	mov r8, r2
	movs r7, #0
	movs r3, #1
	mov sl, r3
_0820D876:
	mov r0, r8
	strh r0, [r4]
	strh r6, [r4, #2]
	strh r6, [r4, #4]
	strh r6, [r4, #6]
	str r6, [sp]
	movs r0, #2
	str r0, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	str r4, [sp, #0xc]
	adds r0, r5, #0
	ldr r1, [sp, #0x20]
	movs r2, #0xd
	movs r3, #0x10
	bl MainSprite_Add
	ldr r2, [sp, #0x18]
	ldr r3, _0820DABC @ =0x00000F14
	adds r1, r2, r3
	adds r1, r1, r7
	ldr r0, [r1]
	movs r2, #1
	mov sb, r2
	orrs r0, r2
	str r0, [r1]
	adds r5, #0x60
	movs r3, #0x60
	add r8, r3
	adds r7, #0x60
	movs r0, #1
	rsbs r0, r0, #0
	add sl, r0
	mov r1, sl
	cmp r1, #0
	bge _0820D876
	movs r2, #2
	mov sl, r2
	add r5, sp, #0x10
	movs r4, #0
	adds r0, r5, #0
	strh r4, [r0]
	strh r4, [r5, #2]
	strh r4, [r5, #4]
	strh r4, [r5, #6]
	ldr r3, [sp, #0x18]
	ldr r1, _0820DAC0 @ =0x00000FCC
	adds r0, r3, r1
	str r4, [sp]
	str r2, [sp, #4]
	movs r2, #0x3c
	str r2, [sp, #8]
	adds r3, r5, #0
	str r3, [sp, #0xc]
	ldr r1, [sp, #0x20]
	movs r2, #0xe
	movs r3, #0x10
	bl MainSprite_Add
	ldr r0, [sp, #0x18]
	ldr r2, _0820DAC4 @ =0x00000FD4
	adds r1, r0, r2
	ldr r0, [r1]
	mov r3, sb
	orrs r0, r3
	str r0, [r1]
	add r0, sp, #0x10
	strh r4, [r0]
	strh r4, [r5, #2]
	strh r4, [r5, #4]
	strh r4, [r5, #6]
	ldr r1, [sp, #0x18]
	ldr r2, _0820DAC8 @ =0x0000048C
	adds r0, r1, r2
	str r4, [sp]
	mov r3, sl
	str r3, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	ldr r1, [sp, #0x20]
	movs r2, #0xf
	movs r3, #0x10
	bl MainSprite_Add
	add r0, sp, #0x10
	strh r4, [r0]
	strh r4, [r5, #2]
	strh r4, [r5, #4]
	strh r4, [r5, #6]
	ldr r3, [sp, #0x18]
	ldr r1, _0820DACC @ =0x000004EC
	adds r0, r3, r1
	str r4, [sp]
	mov r2, sl
	str r2, [sp, #4]
	movs r3, #0x3c
	str r3, [sp, #8]
	add r1, sp, #0x10
	str r1, [sp, #0xc]
	ldr r1, [sp, #0x20]
	movs r2, #0x10
	movs r3, #0x10
	bl MainSprite_Add
	add r0, sp, #0x10
	strh r4, [r0]
	strh r4, [r5, #2]
	strh r4, [r5, #4]
	strh r4, [r5, #6]
	ldr r2, [sp, #0x18]
	movs r3, #0x96
	lsls r3, r3, #1
	adds r0, r2, r3
	str r4, [sp]
	mov r1, sl
	str r1, [sp, #4]
	movs r2, #0x3c
	str r2, [sp, #8]
	add r3, sp, #0x10
	str r3, [sp, #0xc]
	ldr r1, [sp, #0x20]
	movs r2, #0x18
	movs r3, #0x10
	bl MainSprite_Add
	add r0, sp, #0x10
	strh r4, [r0]
	strh r4, [r5, #2]
	strh r4, [r5, #4]
	strh r4, [r5, #6]
	movs r6, #0
	ldr r5, [sp, #0x18]
	movs r0, #0xc6
	lsls r0, r0, #1
	adds r4, r5, r0
_0820D988:
	ldr r1, _0820DAD0 @ =0x085AF090
	lsls r0, r6, #2
	adds r0, r0, r1
	ldrh r2, [r0]
	movs r5, #0
	str r5, [sp]
	movs r0, #2
	str r0, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	add r1, sp, #0x10
	str r1, [sp, #0xc]
	adds r0, r4, #0
	ldr r1, [sp, #0x20]
	movs r3, #0x10
	bl MainSprite_Add
	adds r4, #0x60
	adds r6, #1
	cmp r6, #4
	ble _0820D988
	add r1, sp, #0x10
	adds r0, r1, #0
	strh r5, [r0]
	strh r5, [r1, #2]
	strh r5, [r1, #4]
	strh r5, [r1, #6]
	movs r6, #0
	ldr r2, [sp, #0x18]
	movs r3, #0xdb
	lsls r3, r3, #2
	adds r4, r2, r3
_0820D9C8:
	ldr r0, _0820DAD4 @ =0x085AF0A4
	lsls r1, r6, #2
	adds r1, r1, r0
	ldrh r2, [r1]
	movs r5, #0
	str r5, [sp]
	movs r0, #2
	mov r8, r0
	str r0, [sp, #4]
	movs r7, #0x3c
	str r7, [sp, #8]
	add r1, sp, #0x10
	str r1, [sp, #0xc]
	adds r0, r4, #0
	ldr r1, [sp, #0x20]
	movs r3, #0x10
	bl MainSprite_Add
	adds r4, #0x60
	adds r6, #1
	cmp r6, #2
	ble _0820D9C8
	add r4, sp, #0x10
	adds r0, r4, #0
	strh r5, [r0]
	strh r5, [r4, #2]
	strh r5, [r4, #4]
	strh r5, [r4, #6]
	ldr r2, [sp, #0x18]
	ldr r3, _0820DAD8 @ =0x0000054C
	adds r0, r2, r3
	str r5, [sp]
	mov r1, r8
	str r1, [sp, #4]
	str r7, [sp, #8]
	adds r2, r4, #0
	str r2, [sp, #0xc]
	ldr r1, [sp, #0x20]
	movs r2, #0xc
	movs r3, #0x10
	bl MainSprite_Add
	add r0, sp, #0x10
	strh r5, [r0]
	strh r5, [r4, #2]
	strh r5, [r4, #4]
	strh r5, [r4, #6]
	str r5, [sp]
	mov r3, r8
	str r3, [sp, #4]
	str r7, [sp, #8]
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x24]
	ldr r1, [sp, #0x20]
	movs r2, #0x16
	movs r3, #0x10
	bl MainSprite_Add
	ldr r1, [sp, #0x1c]
	ldrb r0, [r1]
	lsls r0, r0, #4
	adds r0, #8
	ldr r2, [sp, #0x28]
	strh r0, [r2]
	add r0, sp, #0x10
	strh r5, [r0]
	strh r5, [r4, #2]
	strh r5, [r4, #4]
	strh r5, [r4, #6]
	str r5, [sp]
	mov r3, r8
	str r3, [sp, #4]
	str r7, [sp, #8]
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x30]
	ldr r1, [sp, #0x20]
	movs r2, #0x17
	movs r3, #0x10
	bl MainSprite_Add
	ldr r4, [sp, #0x2c]
	ldr r0, [r4]
	ldr r5, [sp, #0x18]
	ldr r1, _0820DADC @ =0x000010EC
	adds r4, r5, r1
	ldr r2, _0820DAE0 @ =0x04000008
	adds r1, r4, #0
	bl CpuSet
	ldr r2, [sp, #0x2c]
	str r4, [r2]
	movs r3, #0x8a
	lsls r3, r3, #1
	adds r1, r5, r3
	str r4, [r1]
	add sp, #0x38
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0820DA98: .4byte 0x0000CB05
_0820DA9C: .4byte 0x00005EBF
_0820DAA0: .4byte 0x000005AC
_0820DAA4: .4byte 0x0000084C
_0820DAA8: .4byte 0x00000E4C
_0820DAAC: .4byte 0x00000D8C
_0820DAB0: .4byte 0x0000102C
_0820DAB4: .4byte 0x0000108C
_0820DAB8: .4byte 0x00000F0C
_0820DABC: .4byte 0x00000F14
_0820DAC0: .4byte 0x00000FCC
_0820DAC4: .4byte 0x00000FD4
_0820DAC8: .4byte 0x0000048C
_0820DACC: .4byte 0x000004EC
_0820DAD0: .4byte 0x085AF090
_0820DAD4: .4byte 0x085AF0A4
_0820DAD8: .4byte 0x0000054C
_0820DADC: .4byte 0x000010EC
_0820DAE0: .4byte 0x04000008
