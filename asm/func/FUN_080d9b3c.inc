	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	str r1, [sp, #0x10]
	mov sl, r2
	str r3, [sp, #0x14]
	ldr r5, [sp, #0x4c]
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r0, _080D9B6C @ =0x0300015C
	ldr r0, [r0]
	cmp r0, #0
	bne _080D9B70
	bl Entity080da848_Create
	mov sb, r0
	cmp r0, #0
	bne _080D9B72
_080D9B66:
	movs r0, #0
	b _080D9CDA
	.align 2, 0
_080D9B6C: .4byte 0x0300015C
_080D9B70:
	mov sb, r0
_080D9B72:
	cmp r5, #0
	beq _080D9B66
	mov r0, sb
	bl FUN_080d99c4
	adds r7, r0, #0
	cmp r7, #0
	beq _080D9B66
	movs r1, #0x98
	lsls r1, r1, #1
	adds r0, r7, r1
	str r5, [r0]
	movs r2, #0x2c
	adds r2, r2, r7
	mov r8, r2
	movs r2, #0
	mov r3, r8
	strb r4, [r3]
	adds r0, r7, #0
	adds r0, #0x2d
	movs r1, #1
	strb r1, [r0]
	adds r3, r7, #0
	adds r3, #0x3a
	strb r2, [r3]
	adds r6, r7, #0
	adds r6, #0x2f
	ldr r0, [sp, #0x44]
	strb r0, [r6]
	movs r4, #0
	strh r2, [r7, #0x30]
	mov r5, sl
	strh r5, [r7, #0x24]
	mov r0, sp
	ldrh r0, [r0, #0x14]
	strh r0, [r7, #0x26]
	ldr r0, [sp, #0x40]
	strh r0, [r7, #0x28]
	adds r0, r7, #0
	adds r0, #0x32
	strb r1, [r0]
	movs r0, #0xa
	strh r0, [r7, #0x3c]
	adds r5, r7, #0
	adds r5, #0x3b
	strb r4, [r5]
	adds r4, r7, #0
	adds r4, #0x44
	strb r1, [r4]
	ldr r1, [sp, #0x10]
	str r1, [r7]
	ldr r0, [sp, #0x48]
	str r0, [r7, #0x58]
	str r2, [sp, #0xc]
	str r2, [sp, #8]
	movs r2, #0x5c
	adds r2, r2, r7
	mov sl, r2
	ldrb r0, [r3]
	mov r1, r8
	str r1, [sp, #0x18]
	mov r8, r3
	str r4, [sp, #0x1c]
	mov r4, sl
	cmp r0, #1
	beq _080D9C10
	cmp r0, #1
	bgt _080D9C00
	cmp r0, #0
	beq _080D9C0A
	b _080D9C16
_080D9C00:
	cmp r0, #5
	bgt _080D9C16
	cmp r0, #4
	blt _080D9C16
	b _080D9C10
_080D9C0A:
	mov r1, sb
	adds r1, #0x18
	b _080D9C18
_080D9C10:
	mov r1, sb
	adds r1, #0x34
	b _080D9C18
_080D9C16:
	movs r1, #0
_080D9C18:
	mov r0, sl
	movs r2, #0
	bl AuxSprite_Add
	ldrb r0, [r6]
	cmp r0, #0xff
	bne _080D9C38
	movs r2, #0x98
	lsls r2, r2, #1
	adds r0, r7, r2
	ldr r0, [r0]
	ldr r1, [r0, #0x34]
	ldr r0, [r0, #0x30]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	b _080D9C60
_080D9C38:
	ldrb r0, [r5]
	ldrb r1, [r6]
	movs r3, #0x98
	lsls r3, r3, #1
	adds r2, r7, r3
	ldr r2, [r2]
	ldrb r2, [r2, #5]
	add r3, sp, #0xc
	str r3, [sp]
	ldr r3, [r7, #0x58]
	str r3, [sp, #4]
	add r3, sp, #8
	bl FUN_080d8cc0
	ldr r0, [sp, #8]
	movs r1, #0
	strh r0, [r7, #0x1c]
	strh r1, [r7, #0x1e]
	ldr r0, [sp, #0xc]
	strh r0, [r7, #0x20]
_080D9C60:
	mov r5, sl
	ldr r0, [r5]
	movs r1, #1
	orrs r0, r1
	str r0, [r5]
	strb r1, [r5, #7]
	movs r0, #0x85
	lsls r0, r0, #1
	adds r1, r7, r0
	movs r0, #0xff
	strh r0, [r1]
	mov r1, r8
	ldrb r0, [r1]
	cmp r0, #5
	bhi _080D9CB0
	lsls r0, r0, #2
	ldr r1, _080D9C88 @ =_080D9C8C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D9C88: .4byte _080D9C8C
_080D9C8C: @ jump table
	.4byte _080D9CA4 @ case 0
	.4byte _080D9CB0 @ case 1
	.4byte _080D9CAA @ case 2
	.4byte _080D9CAA @ case 3
	.4byte _080D9CB0 @ case 4
	.4byte _080D9CB0 @ case 5
_080D9CA4:
	mov r2, sb
	ldr r3, [r2, #0x50]
	b _080D9CB2
_080D9CAA:
	mov r5, sb
	ldr r3, [r5, #0x54]
	b _080D9CB2
_080D9CB0:
	movs r3, #0
_080D9CB2:
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r5, [sp, #0x18]
	ldrb r2, [r5]
	movs r1, #0
	str r1, [sp]
	adds r1, r3, #0
	movs r3, #0
	bl FUN_08236fac
	ldr r2, [sp, #0x10]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r4, #0x1c]
	str r1, [r4, #0x20]
	movs r0, #1
	ldr r3, [sp, #0x1c]
	strb r0, [r3]
	adds r0, r7, #0
_080D9CDA:
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
