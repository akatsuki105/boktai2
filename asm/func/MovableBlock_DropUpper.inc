	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov ip, r0
	ldr r0, _08003674 @ =0x03000020
	ldr r7, [r0]
	ldr r3, [r7, #0x70]
	movs r6, #0
	ldrh r0, [r7, #0x18]
	cmp r6, r0
	bge _08003690
	movs r1, #0xf
	mov r8, r1
	ldr r2, _08003678 @ =MovableBlock_UpdateFall
	mov sl, r2
	movs r0, #0
	mov sb, r0
_0800360A:
	ldrb r0, [r3, #0x1e]
	cmp r0, #0
	beq _08003682
	cmp r3, ip
	beq _08003682
	adds r2, r3, #0
	adds r2, #0xbc
	mov r5, ip
	adds r5, #0xbc
	adds r0, r3, #0
	adds r0, #0xba
	mov r1, ip
	adds r1, #0xba
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bne _08003682
	ldrh r4, [r3, #4]
	cmp r4, #0
	bne _08003682
	ldrb r0, [r2]
	ldrb r2, [r5]
	mov r1, r8
	ands r1, r0
	mov r0, r8
	ands r0, r2
	cmp r1, r0
	bls _08003682
	movs r1, #0xcc
	lsls r1, r1, #1
	adds r0, r3, r1
	mov r2, sl
	str r2, [r0]
	strh r4, [r3, #2]
	movs r0, #1
	strb r0, [r3, #0x11]
	movs r0, #2
	strh r0, [r3, #4]
	strh r4, [r3, #0xc]
	strh r4, [r3, #0xe]
	mov r0, sb
	strb r0, [r3, #0x10]
	ldrh r1, [r3, #0x36]
	strh r1, [r3, #0x12]
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xff
	bls _08003680
	ldr r2, _0800367C @ =0xFFFFFF00
	adds r0, r1, r2
	strh r0, [r3, #0x12]
	b _08003682
	.align 2, 0
_08003674: .4byte 0x03000020
_08003678: .4byte MovableBlock_UpdateFall
_0800367C: .4byte 0xFFFFFF00
_08003680:
	strh r4, [r3, #0x12]
_08003682:
	adds r6, #1
	movs r0, #0xce
	lsls r0, r0, #1
	adds r3, r3, r0
	ldrh r1, [r7, #0x18]
	cmp r6, r1
	blt _0800360A
_08003690:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
