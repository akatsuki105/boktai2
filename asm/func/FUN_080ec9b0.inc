	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	bl FUN_080ec968
	adds r1, r0, #0
	cmp r1, #0
	ble _080ECA64
	ldr r0, _080EC9D8 @ =0x03002C60
	ldr r5, [r0]
	ldr r4, [r5, #4]
	movs r7, #0
	cmp r1, #4
	bgt _080EC9DC
	movs r0, #1
	mov r8, r0
	subs r6, r1, #1
	b _080EC9F8
	.align 2, 0
_080EC9D8: .4byte 0x03002C60
_080EC9DC:
	cmp r1, #9
	bgt _080EC9EA
	movs r0, #2
	mov r8, r0
	adds r0, r1, #1
	movs r1, #2
	b _080EC9F2
_080EC9EA:
	movs r0, #4
	mov r8, r0
	adds r0, r1, #3
	movs r1, #4
_080EC9F2:
	bl Div
	subs r6, r0, #1
_080EC9F8:
	cmp r4, #0
	beq _080ECA64
	movs r1, #3
	mov sl, r1
	movs r0, #0
	mov sb, r0
_080ECA04:
	adds r0, r4, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080ECA20
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	mov r1, sl
	ands r0, r1
	cmp r0, #0
	beq _080ECA30
_080ECA20:
	ldr r1, _080ECA2C @ =0x0000048E
	adds r0, r4, r1
	mov r1, sb
	strb r1, [r0]
	b _080ECA5C
	.align 2, 0
_080ECA2C: .4byte 0x0000048E
_080ECA30:
	ldr r0, _080ECA40 @ =0x0000048E
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _080ECA44
	subs r0, #1
	strb r0, [r1]
	b _080ECA5C
	.align 2, 0
_080ECA40: .4byte 0x0000048E
_080ECA44:
	cmp r7, r8
	bge _080ECA5C
	strb r6, [r1]
	movs r1, #0x80
	lsls r1, r1, #7
	movs r0, #0xc1
	lsls r0, r0, #1
	adds r2, r4, r0
	ldrh r0, [r2]
	orrs r1, r0
	strh r1, [r2]
	adds r7, #1
_080ECA5C:
	ldr r5, [r5]
	ldr r4, [r5, #4]
	cmp r4, #0
	bne _080ECA04
_080ECA64:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
