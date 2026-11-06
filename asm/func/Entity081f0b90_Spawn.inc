	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	adds r6, r0, #0
	mov sl, r1
	str r2, [sp, #0xc]
	str r3, [sp, #0x10]
	ldr r0, _081F0994 @ =0x030001E4
	ldr r0, [r0]
	mov r8, r0
	cmp r0, #0
	bne _081F0916
	bl Entity081f0b90_Create
	mov r8, r0
	cmp r0, #0
	bne _081F0916
	b _081F0A8A
_081F0916:
	mov r0, r8
	bl Entity081f0b90_TryAllocElem
	adds r7, r0, #0
	cmp r7, #0
	bne _081F0924
	b _081F0A8A
_081F0924:
	movs r1, #0xa9
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r1, #0
	movs r2, #1
	strb r2, [r0]
	movs r3, #0xa8
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r1, [r0]
	adds r3, #8
	adds r0, r7, r3
	strh r1, [r0]
	movs r1, #0xad
	lsls r1, r1, #1
	adds r0, r7, r1
	strb r2, [r0]
	adds r2, r7, #0
	adds r2, #0xf0
	ldr r0, [r6]
	ldr r1, [r6, #4]
	str r0, [r2]
	str r1, [r2, #4]
	movs r2, #0xaa
	lsls r2, r2, #1
	adds r1, r7, r2
	ldr r0, [sp, #0x3c]
	strh r0, [r1]
	adds r2, r7, #0
	adds r2, #0xf8
	ldr r0, [r6]
	ldr r1, [r6, #4]
	str r0, [r2]
	str r1, [r2, #4]
	adds r1, r7, #0
	adds r1, #0xfa
	ldr r3, _081F0998 @ =0xFFFFFD00
	adds r0, r3, #0
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	add r5, sp, #4
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _081F099C
	asrs r0, r0, #8
	b _081F09A2
	.align 2, 0
_081F0994: .4byte 0x030001E4
_081F0998: .4byte 0xFFFFFD00
_081F099C:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_081F09A2:
	strh r0, [r5]
	adds r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _081F09B4
	asrs r0, r0, #8
	b _081F09BA
_081F09B4:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_081F09BA:
	adds r4, r0, #0
	movs r3, #2
	ldrsh r1, [r6, r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _081F09CE
	asrs r0, r0, #8
	b _081F09D4
_081F09CE:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_081F09D4:
	subs r2, r4, r0
	adds r4, r4, r0
	ldr r3, _081F0A9C @ =0x030047C8
	ldrh r0, [r5]
	ldrh r1, [r3]
	subs r0, r0, r1
	adds r0, #0x78
	strh r0, [r5]
	ldrh r0, [r3, #2]
	subs r2, r2, r0
	adds r2, #0x5a
	strh r2, [r5, #2]
	ldrh r0, [r3, #4]
	subs r4, r4, r0
	strh r4, [r5, #4]
	movs r6, #0
	mov r5, r8
	adds r5, #0x18
_081F09F8:
	movs r0, #0x2c
	adds r4, r6, #0
	muls r4, r0, r4
	adds r4, r7, r4
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	bl AuxSprite_Add
	ldr r0, [r4]
	movs r1, #0x11
	orrs r0, r1
	str r0, [r4]
	movs r0, #1
	strb r0, [r4, #7]
	adds r6, #1
	cmp r6, #3
	ble _081F09F8
	movs r6, #0
	ldr r0, _081F0AA0 @ =0x030046B8
	mov sb, r0
	adds r5, r7, #0
	adds r5, #0xb0
_081F0A26:
	movs r0, #0x2c
	adds r4, r6, #0
	muls r4, r0, r4
	adds r4, r7, r4
	mov r2, r8
	ldr r1, [r2, #0x34]
	movs r0, #0
	str r0, [sp]
	adds r0, r5, #0
	movs r2, #0xf
	movs r3, #0
	bl AuxAnim_SetAnim
	mov r3, sb
	ldr r0, [r3]
	adds r0, #1
	ldr r1, _081F0AA4 @ =0x000003FF
	ands r0, r1
	str r0, [r3]
	lsls r0, r0, #1
	ldr r1, _081F0AA8 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #3
	ands r0, r1
	strh r0, [r5, #8]
	ldr r0, [r4, #0xc]
	movs r1, #0xfa
	bl Video_SetAuxSpritePltt
	ldr r0, [sp, #4]
	ldr r1, [sp, #8]
	str r0, [r4, #0x1c]
	str r1, [r4, #0x20]
	lsls r0, r6, #5
	ldrh r2, [r4, #0x1e]
	adds r0, r0, r2
	strh r0, [r4, #0x1e]
	adds r5, #0x10
	adds r6, #1
	cmp r6, #2
	ble _081F0A26
	ldr r0, [sp, #0x34]
	str r0, [sp]
	adds r0, r7, #0
	mov r1, sl
	ldr r2, [sp, #0xc]
	ldr r3, [sp, #0x10]
	bl Entity081f0b90Elem_InitHitbox
_081F0A8A:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081F0A9C: .4byte 0x030047C8
_081F0AA0: .4byte 0x030046B8
_081F0AA4: .4byte 0x000003FF
_081F0AA8: .4byte 0x0203B400
