	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x44
	str r1, [sp, #0x14]
	str r2, [sp, #0x18]
	str r3, [sp, #0x1c]
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r0, _080DA13C @ =0x0300015C
	ldr r0, [r0]
	cmp r0, #0
	bne _080DA140
	bl Entity080da848_Create
	str r0, [sp, #0x20]
	cmp r0, #0
	bne _080DA142
_080DA138:
	movs r0, #0
	b _080DA346
	.align 2, 0
_080DA13C: .4byte 0x0300015C
_080DA140:
	str r0, [sp, #0x20]
_080DA142:
	ldr r0, [sp, #0x74]
	cmp r0, #0
	beq _080DA138
	ldr r0, [sp, #0x6c]
	movs r1, #3
	bl Div
	str r0, [sp, #0x28]
	ldr r0, [sp, #0x20]
	bl FUN_080d99c4
	adds r7, r0, #0
	adds r1, r7, #0
	adds r1, #0x88
	str r1, [sp, #0x24]
	cmp r7, #0
	beq _080DA138
	adds r2, r7, #0
	adds r2, #0x2c
	str r2, [sp, #0x2c]
	movs r4, #0
	strb r5, [r2]
	movs r3, #0x2f
	adds r3, r3, r7
	mov sb, r3
	ldr r0, [sp, #0x64]
	strb r0, [r3]
	ldr r0, [sp, #0x68]
	str r0, [r7, #0x48]
	adds r1, r7, #0
	adds r1, #0x2d
	movs r0, #1
	strb r0, [r1]
	movs r5, #0x3a
	adds r5, r5, r7
	mov r8, r5
	movs r5, #3
	mov r0, r8
	strb r5, [r0]
	movs r6, #0
	strh r4, [r7, #0x30]
	mov r1, sp
	ldrh r1, [r1, #0x18]
	strh r1, [r7, #0x24]
	strh r4, [r7, #0x26]
	mov r2, sp
	ldrh r2, [r2, #0x1c]
	strh r2, [r7, #0x28]
	adds r0, r7, #0
	bl FUN_080d8644
	strh r4, [r7, #0x3c]
	strh r4, [r7, #8]
	strh r4, [r7, #6]
	strh r4, [r7, #4]
	adds r2, r7, #0
	adds r2, #0x3b
	strb r5, [r2]
	ldr r3, [sp, #0x14]
	str r3, [r7]
	adds r1, r7, #0
	adds r1, #0x38
	strb r6, [r1]
	adds r0, r7, #0
	adds r0, #0x44
	strb r6, [r0]
	ldr r0, [sp, #0x78]
	str r0, [r7, #0x58]
	movs r5, #0x98
	lsls r5, r5, #1
	adds r0, r7, r5
	ldr r3, [sp, #0x74]
	str r3, [r0]
	movs r5, #0
	mov sl, r5
	ldr r0, [sp, #0x2c]
	str r0, [sp, #0x3c]
	mov r3, sb
	str r3, [sp, #0x40]
	mov r5, r8
	str r5, [sp, #0x34]
	str r2, [sp, #0x38]
	str r1, [sp, #0x30]
	ldr r0, [sp, #0x70]
	cmp sl, r0
	blt _080DA1F0
	b _080DA344
_080DA1F0:
	mov r1, sl
	lsls r3, r1, #2
	adds r1, r7, #0
	adds r1, #0x4c
	adds r1, r1, r3
	mov r2, sl
	lsls r4, r2, #4
	adds r0, r4, r2
	str r0, [r1]
	adds r0, r7, #0
	adds r0, #0x35
	add r0, sl
	movs r2, #0
	strb r2, [r0]
	mov r5, sl
	lsls r1, r5, #1
	adds r0, r7, #0
	adds r0, #0x3e
	adds r0, r0, r1
	ldr r5, [sp, #0x28]
	mov r1, sl
	muls r1, r5, r1
	strh r1, [r0]
	str r2, [sp, #0x10]
	str r2, [sp, #0xc]
	mov r1, sl
	adds r0, r3, r1
	lsls r0, r0, #3
	adds r0, #0x88
	adds r5, r7, r0
	ldr r2, [sp, #0x34]
	ldrb r0, [r2]
	mov sb, r3
	mov r8, r4
	cmp r0, #2
	beq _080DA240
	cmp r0, #3
	beq _080DA246
	movs r1, #0
	b _080DA24A
_080DA240:
	ldr r3, [sp, #0x20]
	ldr r1, [r3, #0x58]
	b _080DA24A
_080DA246:
	ldr r0, [sp, #0x20]
	ldr r1, [r0, #0x58]
_080DA24A:
	adds r0, r5, #0
	movs r2, #0
	bl FUN_0822d9f0
	ldr r1, [sp, #0x38]
	ldrb r0, [r1]
	ldr r2, [sp, #0x40]
	ldrb r1, [r2]
	movs r3, #0x98
	lsls r3, r3, #1
	adds r6, r7, r3
	ldr r2, [r6]
	ldrb r2, [r2, #5]
	add r3, sp, #0xc
	add r4, sp, #0x10
	str r4, [sp]
	ldr r4, [r7, #0x58]
	str r4, [sp, #4]
	bl FUN_080d8cc0
	ldr r1, [sp, #0xc]
	ldr r2, [sp, #0x10]
	adds r0, r5, #0
	bl Particle_SetOffset
	ldr r1, [sp, #0x40]
	ldrb r0, [r1]
	cmp r0, #0xff
	bne _080DA290
	ldr r0, [r6]
	ldr r1, [r0, #0x34]
	ldr r0, [r0, #0x30]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	b _080DA2A0
_080DA290:
	adds r1, r7, #0
	adds r1, #0x1c
	movs r0, #0
	str r0, [sp, #8]
	add r0, sp, #8
	ldr r2, _080DA2D0 @ =0x05000002
	bl CpuSet
_080DA2A0:
	ldr r0, [r5]
	movs r1, #1
	orrs r0, r1
	str r0, [r5]
	movs r0, #0x7f
	strb r0, [r5, #0x10]
	strb r1, [r5, #0xf]
	mov r2, r8
	adds r0, r7, r2
	movs r3, #0x85
	lsls r3, r3, #1
	adds r1, r0, r3
	movs r0, #0xff
	strh r0, [r1]
	ldr r5, [sp, #0x34]
	ldrb r0, [r5]
	cmp r0, #5
	bhi _080DA2FC
	lsls r0, r0, #2
	ldr r1, _080DA2D4 @ =_080DA2D8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080DA2D0: .4byte 0x05000002
_080DA2D4: .4byte _080DA2D8
_080DA2D8: @ jump table
	.4byte _080DA2F0 @ case 0
	.4byte _080DA2FC @ case 1
	.4byte _080DA2F6 @ case 2
	.4byte _080DA2F6 @ case 3
	.4byte _080DA2FC @ case 4
	.4byte _080DA2FC @ case 5
_080DA2F0:
	ldr r0, [sp, #0x20]
	ldr r3, [r0, #0x50]
	b _080DA2FE
_080DA2F6:
	ldr r1, [sp, #0x20]
	ldr r3, [r1, #0x54]
	b _080DA2FE
_080DA2FC:
	movs r3, #0
_080DA2FE:
	movs r0, #0x80
	lsls r0, r0, #1
	add r0, r8
	adds r0, r7, r0
	ldr r5, [sp, #0x3c]
	ldrb r2, [r5]
	movs r1, #0
	str r1, [sp]
	adds r1, r3, #0
	movs r3, #0
	bl FUN_08236fac
	mov r2, sb
	add r2, sl
	lsls r2, r2, #3
	ldr r0, [sp, #0x24]
	adds r2, r2, r0
	ldr r3, [sp, #0x14]
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r2, #0x18]
	str r1, [r2, #0x1c]
	movs r0, #1
	mov r5, sl
	lsls r0, r5
	ldr r2, [sp, #0x30]
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
	movs r3, #1
	add sl, r3
	ldr r5, [sp, #0x70]
	cmp sl, r5
	bge _080DA344
	b _080DA1F0
_080DA344:
	adds r0, r7, #0
_080DA346:
	add sp, #0x44
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
