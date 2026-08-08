	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x14
	mov r8, r1
	mov ip, r2
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	adds r1, r3, #0
	ldr r5, _0824BF00 @ =0x0000FFFF
	adds r7, r5, #0
	adds r2, r5, #0
	movs r0, #1
	ands r0, r3
	cmp r0, #0
	beq _0824BEDE
	ldr r7, _0824BF04 @ =0x00007F7E
_0824BEDE:
	movs r0, #2
	ands r0, r3
	cmp r0, #0
	beq _0824BEE8
	ldr r5, _0824BF08 @ =0x00007F7C
_0824BEE8:
	movs r0, #4
	ands r0, r3
	cmp r0, #0
	beq _0824BEF2
	ldr r2, _0824BF0C @ =0x00007F7A
_0824BEF2:
	cmp r1, #7
	bhi _0824BFAE
	movs r4, #0
	ldr r0, _0824BF10 @ =gRfuLinkStatus
	ldr r1, [r0]
	adds r3, r0, #0
	b _0824BFA8
	.align 2, 0
_0824BF00: .4byte 0x0000FFFF
_0824BF04: .4byte 0x00007F7E
_0824BF08: .4byte 0x00007F7C
_0824BF0C: .4byte 0x00007F7A
_0824BF10: .4byte gRfuLinkStatus
_0824BF14:
	ldr r1, [r3]
	lsls r0, r4, #5
	adds r0, r1, r0
	ldrh r0, [r0, #0x18]
	cmp r0, r7
	beq _0824BF28
	cmp r0, r5
	beq _0824BF28
	cmp r0, r2
	bne _0824BFA2
_0824BF28:
	mov r0, ip
	adds r1, r4, #0
	bl FUN_0824c138
	adds r0, r4, #0
	mov r1, sp
	bl FUN_0824c0c4
	movs r5, #0
_0824BF3A:
	mov r0, sp
	adds r4, r0, r5
	adds r0, r4, #0
	bl FUN_0824c128
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r6, r0
	bne _0824BF7A
	adds r0, r4, #1
	bl FUN_0824c120
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	adds r0, r5, #2
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r4, #7
	bne _0824BF68
	movs r0, #0x11
	subs r0, r0, r5
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
_0824BF68:
	mov r1, sp
	adds r0, r1, r5
	mov r1, r8
	adds r2, r4, #0
	bl FUN_0824c0f8
	lsls r0, r4, #0x18
	asrs r0, r0, #0x18
	b _0824BFB2
_0824BF7A:
	adds r4, #1
	adds r0, r4, #0
	bl FUN_0824c120
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #7
	beq _0824BF9C
	adds r0, r4, #0
	bl FUN_0824c120
	adds r1, r5, #2
	adds r0, r0, r1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0xf
	bls _0824BF3A
_0824BF9C:
	movs r0, #2
	rsbs r0, r0, #0
	b _0824BFB2
_0824BFA2:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
_0824BFA8:
	ldrb r1, [r1, #8]
	cmp r4, r1
	blo _0824BF14
_0824BFAE:
	movs r0, #1
	rsbs r0, r0, #0
_0824BFB2:
	add sp, #0x14
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
