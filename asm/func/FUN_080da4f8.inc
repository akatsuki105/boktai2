	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	str r0, [sp, #0x10]
	mov sb, r1
	adds r5, r2, #0
	adds r4, r3, #0
	ldr r0, _080DA524 @ =0x0300015C
	ldr r0, [r0]
	cmp r0, #0
	bne _080DA528
	bl Entity080da848_Create
	mov r8, r0
	cmp r0, #0
	bne _080DA52A
_080DA51E:
	movs r0, #0
	b _080DA688
	.align 2, 0
_080DA524: .4byte 0x0300015C
_080DA528:
	mov r8, r0
_080DA52A:
	ldr r0, [sp, #0x44]
	cmp r0, #0
	beq _080DA51E
	mov r0, r8
	bl FUN_080d99c4
	adds r7, r0, #0
	cmp r7, #0
	beq _080DA51E
	movs r1, #0x2c
	adds r1, r1, r7
	mov ip, r1
	movs r2, #0
	movs r0, #6
	strb r0, [r1]
	adds r0, r7, #0
	adds r0, #0x2d
	movs r1, #1
	strb r1, [r0]
	strh r5, [r7, #0x26]
	adds r5, r7, #0
	adds r5, #0x2f
	ldr r0, [sp, #0x3c]
	strb r0, [r5]
	strh r4, [r7, #0x28]
	strh r4, [r7, #0x2a]
	adds r4, r7, #0
	adds r4, #0x44
	strb r1, [r4]
	strh r2, [r7, #0x30]
	mov r3, sb
	strh r3, [r7, #0x24]
	adds r3, r7, #0
	adds r3, #0x3b
	movs r0, #5
	strb r0, [r3]
	adds r1, r7, #0
	adds r1, #0x3a
	strb r0, [r1]
	ldr r6, [sp, #0x10]
	str r6, [r7]
	ldr r0, [sp, #0x40]
	str r0, [r7, #0x58]
	movs r6, #0x98
	lsls r6, r6, #1
	adds r0, r7, r6
	ldr r6, [sp, #0x44]
	str r6, [r0]
	str r2, [sp, #0xc]
	str r2, [sp, #8]
	adds r6, r7, #0
	adds r6, #0x5c
	ldrb r0, [r1]
	mov sl, ip
	str r4, [sp, #0x14]
	adds r4, r3, #0
	mov sb, r1
	str r6, [sp, #0x18]
	cmp r0, #1
	beq _080DA5BC
	cmp r0, #1
	bgt _080DA5AC
	cmp r0, #0
	beq _080DA5B6
	b _080DA5C2
_080DA5AC:
	cmp r0, #5
	bgt _080DA5C2
	cmp r0, #4
	blt _080DA5C2
	b _080DA5BC
_080DA5B6:
	mov r1, r8
	adds r1, #0x18
	b _080DA5C4
_080DA5BC:
	mov r1, r8
	adds r1, #0x34
	b _080DA5C4
_080DA5C2:
	movs r1, #0
_080DA5C4:
	adds r0, r6, #0
	movs r2, #0
	bl AuxSprite_Add
	ldrb r0, [r5]
	cmp r0, #0xff
	bne _080DA5E4
	movs r1, #0x98
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	ldr r1, [r0, #0x34]
	ldr r0, [r0, #0x30]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	b _080DA60C
_080DA5E4:
	ldrb r0, [r4]
	ldrb r1, [r5]
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
_080DA60C:
	ldr r0, [r6]
	movs r1, #1
	orrs r0, r1
	str r0, [r6]
	strb r1, [r6, #7]
	movs r6, #0x85
	lsls r6, r6, #1
	adds r1, r7, r6
	movs r0, #0xff
	strh r0, [r1]
	mov r1, sb
	ldrb r0, [r1]
	cmp r0, #5
	bhi _080DA65C
	lsls r0, r0, #2
	ldr r1, _080DA634 @ =_080DA638
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080DA634: .4byte _080DA638
_080DA638: @ jump table
	.4byte _080DA650 @ case 0
	.4byte _080DA65C @ case 1
	.4byte _080DA656 @ case 2
	.4byte _080DA656 @ case 3
	.4byte _080DA65C @ case 4
	.4byte _080DA65C @ case 5
_080DA650:
	mov r2, r8
	ldr r3, [r2, #0x50]
	b _080DA65E
_080DA656:
	mov r6, r8
	ldr r3, [r6, #0x54]
	b _080DA65E
_080DA65C:
	movs r3, #0
_080DA65E:
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r7, r1
	mov r6, sl
	ldrb r2, [r6]
	movs r1, #0
	str r1, [sp]
	adds r1, r3, #0
	movs r3, #0
	bl FUN_08236fac
	ldr r2, [sp, #0x10]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	ldr r3, [sp, #0x18]
	str r0, [r3, #0x1c]
	str r1, [r3, #0x20]
	movs r0, #1
	ldr r6, [sp, #0x14]
	strb r0, [r6]
	adds r0, r7, #0
_080DA688:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
