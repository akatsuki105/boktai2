	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	mov sb, r0
	adds r7, r1, #0
	mov sl, r2
	str r3, [sp, #0xc]
	ldr r0, _081F31E8 @ =0x030001F0
	ldr r6, [r0]
	cmp r6, #0
	bne _081F3138
	bl Entity081f3324_Create
	adds r6, r0, #0
	cmp r6, #0
	bne _081F3138
	b _081F324C
_081F3138:
	adds r0, r6, #0
	bl Entity081f3324_TryAllocElem
	adds r5, r0, #0
	cmp r5, #0
	bne _081F3146
	b _081F324C
_081F3146:
	adds r0, #0xea
	movs r4, #0
	movs r3, #1
	strb r3, [r0]
	subs r0, #2
	strh r4, [r0]
	adds r1, r5, #0
	adds r1, #0xf1
	ldr r0, [sp, #0x38]
	strb r0, [r1]
	adds r2, r5, #0
	adds r2, #0x80
	ldr r0, [r7]
	ldr r1, [r7, #4]
	str r0, [r2]
	str r1, [r2, #4]
	adds r0, r5, #0
	adds r0, #0xf0
	strb r3, [r0]
	mov r8, r5
	adds r1, r6, #0
	adds r1, #0x18
	adds r0, r5, #0
	movs r2, #0
	bl AuxSprite_Add
	adds r0, r5, #0
	adds r0, #0x2c
	ldr r1, [r6, #0x34]
	str r4, [sp]
	movs r2, #0
	movs r3, #0
	bl AuxAnim_SetAnim
	ldr r0, [r5, #0xc]
	movs r1, #1
	bl Video_SetAuxSpritePltt
	mov r2, sb
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r5, #0x1c]
	str r1, [r5, #0x20]
	add r2, sp, #4
	adds r3, r5, #0
	adds r3, #0x1c
	ldrh r0, [r7]
	ldrh r1, [r5, #0x1c]
	subs r0, r0, r1
	adds r1, r2, #0
	strh r0, [r1]
	ldrh r0, [r7, #2]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r7, #4]
	ldrh r1, [r3, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	adds r0, r2, #0
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl ArcTan2_8
	adds r3, r0, #0
	ldr r2, _081F31EC @ =gSineTable
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r2, [sp, #0x3c]
	muls r0, r2, r0
	cmp r0, #0
	blt _081F31F0
	asrs r1, r0, #0xc
	b _081F31F6
	.align 2, 0
_081F31E8: .4byte 0x030001F0
_081F31EC: .4byte gSineTable
_081F31F0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081F31F6:
	adds r0, r5, #0
	adds r0, #0x88
	strh r1, [r0]
	ldr r1, _081F3218 @ =gSineTable
	movs r0, #0xff
	ands r0, r3
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	ldr r1, [sp, #0x3c]
	muls r0, r1, r0
	cmp r0, #0
	blt _081F321C
	asrs r2, r0, #0xc
	b _081F3222
	.align 2, 0
_081F3218: .4byte gSineTable
_081F321C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_081F3222:
	adds r0, r5, #0
	adds r0, #0x8c
	movs r1, #0
	strh r2, [r0]
	subs r0, #2
	strh r1, [r0]
	mov r2, r8
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r0, #2
	strb r0, [r2, #7]
	ldr r0, [sp, #0x34]
	str r0, [sp]
	adds r0, r5, #0
	mov r1, sl
	ldr r2, [sp, #0xc]
	ldr r3, [sp, #0x30]
	bl Entity081f3324_InitHitbox
_081F324C:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
