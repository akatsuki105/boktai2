	push {r4, r5, r6, r7, lr}
	sub sp, #0x30
	adds r7, r0, #0
	ldr r1, [sp, #0x44]
	ldr r5, [sp, #0x4c]
	ldr r6, [sp, #0x50]
	mov r0, sp
	movs r4, #0
	strh r2, [r0]
	strh r3, [r0, #2]
	strh r1, [r0, #6]
	strh r4, [r0, #8]
	strh r4, [r0, #0xa]
	add r1, sp, #0x48
	ldrh r1, [r1]
	strh r1, [r0, #0xc]
	strh r4, [r0, #0xe]
	ldr r2, _08015E74 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08015E78 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _08015E7C @ =0x0203B400
	adds r0, r0, r2
	mov r1, sp
	ldrb r0, [r0]
	strh r0, [r1, #0x14]
	mov r0, sp
	strh r4, [r0, #0x16]
	strh r4, [r0, #0x12]
	strh r4, [r0, #0x10]
	strh r5, [r0, #0x18]
	strh r4, [r0, #0x1a]
	strh r6, [r0, #0x1c]
	strh r4, [r0, #0x1e]
	strh r5, [r0, #0x20]
	strh r4, [r0, #0x22]
	strh r6, [r0, #0x24]
	strh r4, [r0, #0x26]
	ldr r2, _08015E80 @ =0x085B0A08
	ldrh r0, [r0, #0x14]
	adds r0, #0xc0
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	ldr r1, [sp, #0x48]
	muls r0, r1, r0
	cmp r0, #0
	blt _08015E84
	asrs r1, r0, #0xc
	b _08015E8A
	.align 2, 0
_08015E74: .4byte 0x030046B8
_08015E78: .4byte 0x000003FF
_08015E7C: .4byte 0x0203B400
_08015E80: .4byte 0x085B0A08
_08015E84:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08015E8A:
	ldrh r0, [r7]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	ldrh r1, [r7, #2]
	lsls r1, r1, #0x10
	lsrs r0, r0, #0x10
	orrs r0, r1
	str r0, [sp, #0x28]
	mov r0, sp
	ldrh r0, [r0, #0x14]
	adds r0, #0x80
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	ldr r3, [sp, #0x48]
	muls r0, r3, r0
	cmp r0, #0
	blt _08015EBE
	asrs r0, r0, #0xc
	b _08015EC4
_08015EBE:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08015EC4:
	ldrh r2, [r7, #4]
	adds r2, r2, r0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	ldr r3, _08015EE8 @ =0xFFFF0000
	add r1, sp, #0x28
	ldr r0, [r1, #4]
	ands r0, r3
	orrs r0, r2
	str r0, [r1, #4]
	movs r0, #1
	mov r2, sp
	bl FUN_080155e4
	add sp, #0x30
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08015EE8: .4byte 0xFFFF0000
