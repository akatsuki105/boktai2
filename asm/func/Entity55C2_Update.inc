	push {r4, r5, r6, lr}
	sub sp, #0x1c
	adds r4, r0, #0
	adds r6, r4, #0
	adds r6, #0x18
	adds r1, r4, #0
	adds r1, #0x7c
	ldrh r0, [r1]
	cmp r0, #0
	beq _0800E194
	subs r0, #1
	strh r0, [r1]
	ldrh r1, [r4, #0x1e]
	movs r0, #4
	orrs r0, r1
	b _0800E19A
_0800E194:
	ldrh r1, [r4, #0x1e]
	ldr r0, _0800E204 @ =0x0000FFFB
	ands r0, r1
_0800E19A:
	strh r0, [r4, #0x1e]
	ldrh r0, [r6, #0x3e]
	cmp r0, #0
	beq _0800E246
	adds r0, r4, #0
	adds r0, #0x7e
	ldrh r1, [r0]
	subs r0, #2
	strh r1, [r0]
	adds r5, r4, #0
	adds r5, #0x6a
	ldrh r0, [r5]
	ldrh r1, [r6, #0x3e]
	subs r0, r0, r1
	strh r0, [r5]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _0800E212
	adds r1, r4, #0
	adds r1, #0x82
	ldrh r0, [r1]
	cmp r0, #0
	beq _0800E1EE
	adds r0, r4, #0
	adds r0, #0x84
	movs r2, #0
	ldrsh r0, [r0, r2]
	str r0, [sp]
	adds r0, r4, #0
	adds r0, #0x86
	movs r2, #0
	ldrsh r0, [r0, r2]
	str r0, [sp, #4]
	adds r0, r4, #0
	adds r0, #0x88
	movs r2, #0
	ldrsh r0, [r0, r2]
	str r0, [sp, #8]
	ldrh r0, [r1]
	add r1, sp, #0xc
	bl VM_ExecByID
_0800E1EE:
	adds r0, r4, #0
	adds r0, #0x6e
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0800E208
	adds r0, r4, #0
	bl KillEntity
	b _0800E242
	.align 2, 0
_0800E204: .4byte 0x0000FFFB
_0800E208:
	adds r0, r4, #0
	adds r0, #0x6c
	ldrh r0, [r0]
	strh r0, [r5]
	b _0800E242
_0800E212:
	adds r1, r4, #0
	adds r1, #0x80
	ldrh r0, [r1]
	cmp r0, #0
	beq _0800E242
	adds r0, r4, #0
	adds r0, #0x84
	movs r2, #0
	ldrsh r0, [r0, r2]
	str r0, [sp]
	adds r0, r4, #0
	adds r0, #0x86
	movs r2, #0
	ldrsh r0, [r0, r2]
	str r0, [sp, #4]
	adds r0, r4, #0
	adds r0, #0x88
	movs r2, #0
	ldrsh r0, [r0, r2]
	str r0, [sp, #8]
	ldrh r0, [r1]
	add r1, sp, #0x14
	bl VM_ExecByID
_0800E242:
	movs r0, #0
	strh r0, [r6, #0x3e]
_0800E246:
	movs r0, #0
	add sp, #0x1c
	pop {r4, r5, r6}
	pop {r1}
	bx r1
