	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	adds r5, r0, #0
	adds r6, r2, #0
	ldr r2, _08000948 @ =0x03000000
	ldrb r0, [r6, #1]
	lsls r0, r0, #2
	adds r0, r0, r2
	str r5, [r0]
	strh r1, [r5, #0x18]
	ldrb r0, [r6]
	strb r0, [r5, #0x1a]
	ldrb r0, [r6, #1]
	strb r0, [r5, #0x1b]
	ldrb r1, [r5, #0x1b]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	ldr r1, _0800094C @ =0x03003ED0
	adds r0, r0, r1
	mov sl, r0
	ldrh r0, [r6, #2]
	str r0, [r5, #0x1c]
	bl GetTilemapFile
	str r0, [sp, #0x10]
	ldrb r1, [r5, #0x1a]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08000954
	ldr r0, _08000950 @ =0x000056C2
	bl Registry_Find
	ldr r0, [r0, #4]
	movs r2, #8
	ldrsh r1, [r0, r2]
	mov r8, r1
	movs r4, #0xa
	ldrsh r3, [r0, r4]
	mov sb, r3
	b _0800095A
	.align 2, 0
_08000948: .4byte 0x03000000
_0800094C: .4byte 0x03003ED0
_08000950: .4byte 0x000056C2
_08000954:
	movs r0, #0
	mov r8, r0
	mov sb, r0
_0800095A:
	ldrb r1, [r5, #0x1a]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08000988
	ldr r3, _08000980 @ =0x030047C8
	movs r2, #0
	ldrsh r1, [r3, r2]
	ldr r2, _08000984 @ =0x03003540
	movs r4, #8
	ldrsh r0, [r2, r4]
	adds r4, r1, r0
	movs r0, #2
	ldrsh r1, [r3, r0]
	movs r3, #0xa
	ldrsh r0, [r2, r3]
	adds r2, r1, r0
	b _0800098C
	.align 2, 0
_08000980: .4byte 0x030047C8
_08000984: .4byte 0x03003540
_08000988:
	ldr r4, [r6, #4]
	ldr r2, [r6, #8]
_0800098C:
	ldr r0, [r6, #0x14]
	adds r1, r5, #0
	adds r1, #0x76
	movs r3, #0
	strh r0, [r1]
	adds r0, r4, #0
	subs r0, #0x78
	mov r1, sl
	strh r0, [r1, #0x20]
	adds r0, r2, #0
	subs r0, #0x5a
	strh r0, [r1, #0x22]
	lsls r1, r4, #7
	str r1, [r5, #0x20]
	lsls r0, r2, #7
	str r0, [r5, #0x24]
	str r1, [r5, #0x28]
	str r0, [r5, #0x2c]
	str r1, [r5, #0x40]
	str r0, [r5, #0x44]
	ldr r0, [r6, #0xc]
	str r0, [r5, #0x30]
	ldr r0, [r6, #0x10]
	str r0, [r5, #0x34]
	str r3, [r5, #0x38]
	str r3, [r5, #0x3c]
	mov r2, r8
	asrs r0, r2, #7
	str r0, [r5, #0x50]
	mov r4, sb
	asrs r0, r4, #7
	str r0, [r5, #0x54]
	ldr r0, [r6, #0x28]
	str r0, [r5, #0x58]
	ldr r0, [r6, #0x2c]
	str r0, [r5, #0x5c]
	ldr r0, [r6, #0x18]
	lsls r0, r0, #0xa
	str r0, [r5, #0x60]
	ldr r0, [r6, #0x1c]
	lsls r0, r0, #0xa
	str r0, [r5, #0x64]
	ldr r0, [r6, #0x20]
	str r0, [r5, #0x68]
	ldr r0, [r6, #0x24]
	str r0, [r5, #0x6c]
	adds r0, r5, #0
	adds r0, #0x70
	strh r3, [r0]
	adds r0, #4
	strh r3, [r0]
	subs r0, #2
	strh r3, [r0]
	adds r0, #6
	strh r3, [r0]
	ldr r0, [r6, #0x38]
	lsls r0, r0, #8
	adds r2, r5, #0
	adds r2, #0x7c
	strh r0, [r2]
	ldr r0, [r6, #0x3c]
	lsls r0, r0, #8
	movs r1, #0x7e
	adds r1, r1, r5
	mov ip, r1
	strh r0, [r1]
	adds r4, r5, #0
	adds r4, #0x88
	strh r3, [r4]
	adds r7, r5, #0
	adds r7, #0x8a
	strh r3, [r7]
	ldrh r1, [r2]
	adds r0, r5, #0
	adds r0, #0x84
	strh r1, [r0]
	mov r3, ip
	ldrh r0, [r3]
	adds r1, r5, #0
	adds r1, #0x86
	strh r0, [r1]
	ldrh r0, [r2]
	strh r0, [r4]
	ldrh r0, [r3]
	strh r0, [r7]
	ldrb r1, [r5, #0x1a]
	movs r0, #0x10
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	rsbs r0, r0, #0
	lsrs r7, r0, #0x1f
	ldr r4, [sp, #0x10]
	ldrb r0, [r4]
	cmp r0, #0x4d
	bne _08000A60
	ldrb r0, [r4, #1]
	cmp r0, #0x50
	bne _08000A60
	mov r0, sl
	strh r7, [r0]
	ldrb r0, [r5, #0x1b]
	ldr r1, [r6, #0x30]
	bl SetBGPrioDirect
	b _08000A82
_08000A60:
	ldrb r0, [r5, #0x1b]
	bl GetTilemapBuffer
	ldrb r3, [r5, #0x1b]
	adds r1, r7, #0
	mov r2, r8
	str r2, [sp]
	mov r4, sb
	str r4, [sp, #4]
	ldr r2, [r6, #0x30]
	str r2, [sp, #8]
	str r0, [sp, #0xc]
	adds r0, r3, #0
	ldr r2, [sp, #0x10]
	movs r3, #0
	bl Video_SetupBG
_08000A82:
	movs r0, #0
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
