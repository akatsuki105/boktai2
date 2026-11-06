	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	mov sl, r0
	mov sb, r2
	adds r5, r3, #0
	ldr r0, _081F4424 @ =0x030001F4
	ldr r6, [r0]
	cmp r6, #0
	bne _081F42F2
	bl Entity081f4554_Create
	adds r6, r0, #0
	cmp r6, #0
	bne _081F42F2
	b _081F4412
_081F42F2:
	adds r0, r6, #0
	bl Entity081f4554_TryAllocElem
	adds r4, r0, #0
	cmp r4, #0
	bne _081F4300
	b _081F4412
_081F4300:
	movs r1, #0xa9
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r2, #0
	mov r8, r2
	movs r7, #1
	strb r7, [r0]
	movs r3, #0xa8
	lsls r3, r3, #1
	adds r0, r4, r3
	mov r1, r8
	strh r1, [r0]
	movs r2, #0xaa
	lsls r2, r2, #1
	adds r0, r4, r2
	strh r1, [r0]
	adds r3, #0x18
	adds r0, r4, r3
	strh r5, [r0]
	ldr r0, _081F4428 @ =0x0000015F
	adds r1, r4, r0
	ldr r0, [sp, #0x4c]
	strb r0, [r1]
	adds r2, #0x10
	adds r1, r4, r2
	ldr r0, [sp, #0x3c]
	strh r0, [r1]
	subs r3, #0xb
	adds r1, r4, r3
	ldr r0, [sp, #0x40]
	strb r0, [r1]
	movs r0, #0xb0
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [sp, #0x44]
	str r0, [r1]
	subs r2, #6
	adds r1, r4, r2
	ldr r0, [sp, #0x48]
	strb r0, [r1]
	adds r3, #0xd
	adds r0, r4, r3
	mov r1, sb
	strh r1, [r0]
	subs r2, #8
	adds r0, r4, r2
	strb r7, [r0]
	adds r3, #6
	adds r1, r4, r3
	ldr r0, [sp, #0x50]
	strh r0, [r1]
	movs r0, #0xb9
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [sp, #0x54]
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0x58
	movs r1, #3
	movs r2, #0
	movs r3, #0
	bl Map_InitPathWalker
	adds r0, r4, #0
	adds r0, #0x64
	adds r1, r4, #0
	adds r1, #0x1c
	movs r2, #0x60
	str r2, [sp]
	movs r2, #0x64
	str r2, [sp, #4]
	movs r2, #0xe0
	lsls r2, r2, #4
	str r2, [sp, #8]
	str r7, [sp, #0xc]
	movs r2, #5
	str r2, [sp, #0x10]
	str r7, [sp, #0x14]
	mov r2, r8
	str r2, [sp, #0x18]
	movs r2, #0x40
	movs r3, #0x10
	bl AuxShadow_Init
	ldr r3, _081F442C @ =0x0000015B
	adds r1, r4, r3
	strb r0, [r1]
	adds r2, r4, #0
	adds r2, #0xd0
	mov r3, sl
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r2]
	str r1, [r2, #4]
	adds r1, r4, #0
	adds r1, #0xd2
	movs r2, #0xf2
	lsls r2, r2, #2
	adds r0, r2, #0
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	adds r5, r4, #0
	adds r5, #0x2c
	ldr r1, _081F4430 @ =0x0000D45E
	adds r0, r5, #0
	bl Video_GetAuxSprite
	cmp r0, #0
	beq _081F4412
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	bl AuxSprite_Add
	ldr r0, [r4]
	orrs r0, r7
	str r0, [r4]
	adds r0, r4, #0
	adds r0, #0x48
	ldr r1, [r6, #0x18]
	mov r2, r8
	str r2, [sp]
	movs r2, #0x17
	movs r3, #0
	bl AuxAnim_SetAnim
	ldr r0, [r4, #0xc]
	movs r1, #0xfb
	bl Video_SetAuxSpritePltt
	mov r3, sl
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r4, #0x1c]
	str r1, [r4, #0x20]
	strb r7, [r4, #7]
_081F4412:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081F4424: .4byte 0x030001F4
_081F4428: .4byte 0x0000015F
_081F442C: .4byte 0x0000015B
_081F4430: .4byte 0x0000D45E
