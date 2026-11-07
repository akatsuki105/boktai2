	push {lr}
	sub sp, #0x30
	adds r2, r0, #0
	movs r1, #0x80
	lsls r1, r1, #0xc
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r0, r2, r3
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _0814B078
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r2, r1
	ldr r1, [r0]
	adds r3, #0x1c
	adds r0, r2, r3
	ldrh r0, [r0]
	cmp r0, #0
	beq _0814B078
	movs r3, #8
	ldrsh r0, [r2, r3]
	str r0, [sp]
	movs r3, #0xa
	ldrsh r0, [r2, r3]
	str r0, [sp, #4]
	movs r3, #0xc
	ldrsh r0, [r2, r3]
	str r0, [sp, #8]
	movs r3, #0xce
	lsls r3, r3, #1
	adds r0, r2, r3
	ldr r0, [r0]
	str r0, [sp, #0xc]
	adds r3, #4
	adds r0, r2, r3
	ldr r0, [r0]
	str r0, [sp, #0x10]
	adds r3, #4
	adds r0, r2, r3
	ldr r0, [r0]
	str r0, [sp, #0x14]
	movs r3, #0xda
	lsls r3, r3, #3
	adds r0, r1, r3
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0
	bge _0814B034
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [sp, #0x18]
	b _0814B046
_0814B034:
	ldr r3, _0814B080 @ =0x000006D2
	adds r0, r1, r3
	movs r3, #0
	ldrsh r0, [r0, r3]
	str r0, [sp, #0x18]
	ldr r3, _0814B084 @ =0x000006D4
	adds r0, r1, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
_0814B046:
	str r0, [sp, #0x1c]
	ldr r3, _0814B088 @ =0x000001DF
	adds r0, r2, r3
	ldrb r0, [r0]
	str r0, [sp, #0x20]
	movs r1, #0x90
	lsls r1, r1, #3
	adds r0, r2, r1
	ldrh r0, [r0]
	str r0, [sp, #0x24]
	ldr r1, _0814B08C @ =0xFFFF0000
	ldr r0, [sp, #0x28]
	ands r0, r1
	movs r1, #0xa
	orrs r0, r1
	str r0, [sp, #0x28]
	add r1, sp, #0x28
	mov r3, sp
	str r3, [r1, #4]
	movs r3, #0xcc
	lsls r3, r3, #1
	adds r0, r2, r3
	ldrh r0, [r0]
	bl VM_ExecByID
_0814B078:
	add sp, #0x30
	pop {r0}
	bx r0
	.align 2, 0
_0814B080: .4byte 0x000006D2
_0814B084: .4byte 0x000006D4
_0814B088: .4byte 0x000001DF
_0814B08C: .4byte 0xFFFF0000
