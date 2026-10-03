	push {r4, r5, r6, r7, lr}
	sub sp, #0x34
	adds r6, r0, #0
	ldr r0, _0809B0C4 @ =0x000009EC
	adds r4, r6, r0
	ldrh r0, [r4]
	lsls r0, r0, #2
	ldr r1, _0809B0C8 @ =0x00001084
	bl FUN_0808a458
	ldrh r0, [r4]
	cmp r0, #0
	bne _0809AF20
	ldr r1, _0809B0CC @ =0x04000050
	movs r2, #0x9b
	lsls r2, r2, #4
	adds r0, r6, r2
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r0, _0809B0D0 @ =0x00003B14
	adds r3, r6, r0
	ldrh r1, [r3]
	movs r4, #0x80
	lsls r4, r4, #2
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq _0809AEF2
	ldr r2, _0809B0D4 @ =0x03003E78
	ldrh r1, [r2]
	adds r0, r4, #0
	orrs r0, r1
	strh r0, [r2]
_0809AEF2:
	ldrh r3, [r3]
	movs r4, #0x80
	lsls r4, r4, #3
	adds r0, r4, #0
	ands r0, r3
	cmp r0, #0
	beq _0809AF0A
	ldr r2, _0809B0D4 @ =0x03003E78
	ldrh r1, [r2]
	adds r0, r4, #0
	orrs r0, r1
	strh r0, [r2]
_0809AF0A:
	movs r4, #0x80
	lsls r4, r4, #4
	adds r0, r4, #0
	ands r0, r3
	cmp r0, #0
	beq _0809AF20
	ldr r2, _0809B0D4 @ =0x03003E78
	ldrh r1, [r2]
	adds r0, r4, #0
	orrs r0, r1
	strh r0, [r2]
_0809AF20:
	ldr r2, _0809B0C4 @ =0x000009EC
	adds r1, r6, r2
	ldrh r0, [r1]
	adds r0, #1
	movs r5, #0
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x10
	bhi _0809AF36
	b _0809B0BC
_0809AF36:
	ldr r1, _0809B0D8 @ =FUN_0808cf14
	adds r0, r6, #0
	bl FUN_0808a33c
	ldr r1, _0809B0DC @ =0x03004494
	ldr r2, _0809B0E0 @ =0x00003B1C
	adds r0, r6, r2
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r1, _0809B0E4 @ =0x03004454
	adds r2, #2
	adds r0, r6, r2
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r1, _0809B0E8 @ =0x03004464
	adds r2, #2
	adds r0, r6, r2
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r1, _0809B0EC @ =0x03004490
	adds r2, #2
	adds r0, r6, r2
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r2, _0809B0F0 @ =0x030044BC
	movs r1, #5
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	bl FUN_0824082c
	ldr r0, _0809B0F4 @ =0x00003FB8
	adds r4, r6, r0
	ldrb r0, [r4]
	cmp r0, #0
	beq _0809AF94
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r6, r1
	ldr r0, [r0]
	ldr r2, _0809B0F8 @ =0x00003FB9
	adds r1, r6, r2
	ldrb r1, [r1]
	bl Entity080aace8_Create
	strb r5, [r4]
_0809AF94:
	ldr r0, _0809B0FC @ =0x00003FB0
	adds r4, r6, r0
	ldrb r0, [r4]
	cmp r0, #0
	beq _0809AFD0
	ldr r1, _0809B100 @ =0x00003FB4
	adds r0, r6, r1
	ldr r2, [r0]
	cmp r2, #0
	beq _0809AFC8
	ldr r1, _0809B104 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	str r0, [sp, #0x10]
	ldr r1, _0809B108 @ =0x00003FB1
	adds r0, r6, r1
	ldrb r0, [r0]
	str r0, [sp, #0xc]
	add r1, sp, #0x10
	add r0, sp, #0xc
	str r0, [r1, #4]
	adds r0, r2, #0
	bl VM_ExecByID
_0809AFC8:
	ldr r1, _0809B108 @ =0x00003FB1
	adds r0, r6, r1
	strb r5, [r0]
	strb r5, [r4]
_0809AFD0:
	ldr r2, _0809B10C @ =0x00003FAC
	adds r0, r6, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _0809B082
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r6, r1
	ldr r0, [r0]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [sp, #0x18]
	str r1, [sp, #0x1c]
	ldr r0, _0809B110 @ =0xFFFFFE00
	adds r2, r0, #0
	add r4, sp, #0x18
	ldrh r0, [r4]
	adds r1, r2, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r3, _0809B104 @ =0xFFFF0000
	ldr r0, [sp, #0x18]
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #0x18]
	ldrh r1, [r4, #4]
	adds r2, r2, r1
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	ldr r0, [r4, #4]
	ands r0, r3
	orrs r0, r2
	str r0, [r4, #4]
	ldr r2, [sp, #0x18]
	asrs r1, r2, #0x10
	ldr r0, _0809B114 @ =0xFFFFFF00
	adds r1, r1, r0
	lsls r1, r1, #0x10
	ldr r5, _0809B118 @ =0x0000FFFF
	adds r0, r5, #0
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x18]
	ldr r0, [sp, #0x20]
	ands r0, r3
	movs r1, #0x80
	lsls r1, r1, #3
	orrs r0, r1
	str r0, [sp, #0x20]
	add r2, sp, #0x20
	ldr r0, [r2, #4]
	ands r0, r3
	orrs r0, r1
	str r0, [r2, #4]
	ldr r0, [sp, #0x20]
	ands r0, r5
	movs r1, #0x80
	lsls r1, r1, #0x12
	orrs r0, r1
	str r0, [sp, #0x20]
	adds r7, r4, #0
	adds r4, r2, #0
	movs r5, #2
_0809B04E:
	ldr r1, _0809B11C @ =0x00003FAD
	adds r0, r6, r1
	ldrb r1, [r0]
	ldr r2, _0809B120 @ =0x00003FAE
	adds r0, r6, r2
	ldrh r2, [r0]
	str r4, [sp]
	movs r0, #0x96
	lsls r0, r0, #1
	str r0, [sp, #4]
	movs r0, #0x78
	str r0, [sp, #8]
	movs r0, #4
	adds r3, r7, #0
	bl Entity0800a89c_Spawn
	subs r5, #1
	cmp r5, #0
	bge _0809B04E
	ldr r1, _0809B11C @ =0x00003FAD
	adds r0, r6, r1
	movs r1, #0
	strb r1, [r0]
	ldr r2, _0809B10C @ =0x00003FAC
	adds r0, r6, r2
	strb r1, [r0]
_0809B082:
	ldr r0, _0809B124 @ =0x00003FBB
	adds r4, r6, r0
	ldrb r0, [r4]
	cmp r0, #0
	beq _0809B0BC
	ldr r1, _0809B100 @ =0x00003FB4
	adds r0, r6, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _0809B0B8
	ldr r1, _0809B104 @ =0xFFFF0000
	ldr r0, [sp, #0x2c]
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	str r0, [sp, #0x2c]
	ldrb r0, [r4]
	subs r0, #1
	str r0, [sp, #0x28]
	add r0, sp, #0x28
	add r1, sp, #0x2c
	str r0, [r1, #4]
	ldr r2, _0809B128 @ =0x00003FBC
	adds r0, r6, r2
	ldr r0, [r0]
	bl VM_ExecByID
_0809B0B8:
	movs r0, #0
	strb r0, [r4]
_0809B0BC:
	add sp, #0x34
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0809B0C4: .4byte 0x000009EC
_0809B0C8: .4byte 0x00001084
_0809B0CC: .4byte 0x04000050
_0809B0D0: .4byte 0x00003B14
_0809B0D4: .4byte 0x03003E78
_0809B0D8: .4byte FUN_0808cf14
_0809B0DC: .4byte 0x03004494
_0809B0E0: .4byte 0x00003B1C
_0809B0E4: .4byte 0x03004454
_0809B0E8: .4byte 0x03004464
_0809B0EC: .4byte 0x03004490
_0809B0F0: .4byte 0x030044BC
_0809B0F4: .4byte 0x00003FB8
_0809B0F8: .4byte 0x00003FB9
_0809B0FC: .4byte 0x00003FB0
_0809B100: .4byte 0x00003FB4
_0809B104: .4byte 0xFFFF0000
_0809B108: .4byte 0x00003FB1
_0809B10C: .4byte 0x00003FAC
_0809B110: .4byte 0xFFFFFE00
_0809B114: .4byte 0xFFFFFF00
_0809B118: .4byte 0x0000FFFF
_0809B11C: .4byte 0x00003FAD
_0809B120: .4byte 0x00003FAE
_0809B124: .4byte 0x00003FBB
_0809B128: .4byte 0x00003FBC
