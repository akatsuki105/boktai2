	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov sb, r0
	adds r4, r1, #0
	mov sl, r2
	str r3, [sp, #4]
	ldr r0, _081F5298 @ =0x030001F8
	ldr r6, [r0]
	cmp r6, #0
	bne _081F51D2
	bl Entity081f53a8_Create
	adds r6, r0, #0
	cmp r6, #0
	beq _081F5288
_081F51D2:
	adds r0, r6, #0
	bl FUN_081f519c
	adds r7, r0, #0
	cmp r7, #0
	beq _081F5288
	movs r1, #0xb7
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r2, #0
	mov r8, r2
	movs r5, #1
	strb r5, [r0]
	subs r1, #2
	adds r0, r7, r1
	mov r2, r8
	strh r2, [r0]
	adds r1, #6
	adds r0, r7, r1
	strb r5, [r0]
	adds r0, r7, #0
	adds r0, #0xf8
	str r4, [r0]
	movs r2, #0xbf
	lsls r2, r2, #1
	adds r1, r7, r2
	ldr r0, [sp, #0x34]
	strh r0, [r1]
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, [sp, #0x38]
	strh r0, [r1]
	subs r2, #0xb
	adds r1, r7, r2
	movs r0, #4
	strb r0, [r1]
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, [sp, #0x30]
	strh r0, [r1]
	adds r2, #9
	adds r1, r7, r2
	movs r0, #0x3c
	strh r0, [r1]
	ldr r0, _081F529C @ =0x00000175
	adds r1, r7, r0
	ldr r0, [sp, #0x3c]
	strb r0, [r1]
	adds r4, r7, #0
	adds r4, #0x2c
	ldr r1, _081F52A0 @ =0x0000D45E
	adds r0, r4, #0
	bl Video_GetAuxSprite
	adds r0, r7, #0
	adds r1, r4, #0
	movs r2, #0
	bl AuxSprite_Add
	adds r0, r7, #0
	adds r0, #0x48
	ldr r1, [r6, #0x18]
	mov r2, r8
	str r2, [sp]
	movs r2, #0x14
	movs r3, #0
	bl AuxAnim_SetAnim
	ldr r0, [r7, #0xc]
	movs r1, #0xfa
	bl Video_SetAuxSpritePltt
	mov r2, sb
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	ldr r0, [r7]
	orrs r0, r5
	str r0, [r7]
	strb r5, [r7, #7]
	ldr r0, [sp, #0x2c]
	str r0, [sp]
	adds r0, r7, #0
	mov r1, sl
	ldr r2, [sp, #4]
	ldr r3, [sp, #0x28]
	bl FUN_081f4758
_081F5288:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081F5298: .4byte 0x030001F8
_081F529C: .4byte 0x00000175
_081F52A0: .4byte 0x0000D45E
