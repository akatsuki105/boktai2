	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x14
	adds r5, r2, #0
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r2, r1, #0
	ldr r6, _0824C004 @ =0x0000FFFF
	mov r8, r6
	mov ip, r6
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0824BFE8
	ldr r0, _0824C008 @ =0x00007F7E
	mov r8, r0
_0824BFE8:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0824BFF2
	ldr r6, _0824C00C @ =0x00007F7C
_0824BFF2:
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _0824BFFE
	ldr r0, _0824C010 @ =0x00007F7A
	mov ip, r0
_0824BFFE:
	cmp r2, #7
	bls _0824C018
	b _0824C0B0
	.align 2, 0
_0824C004: .4byte 0x0000FFFF
_0824C008: .4byte 0x00007F7E
_0824C00C: .4byte 0x00007F7C
_0824C010: .4byte 0x00007F7A
_0824C014:
	adds r0, r6, #0
	b _0824C0B4
_0824C018:
	movs r3, #0
	ldr r0, _0824C05C @ =gRfuLinkStatus
	ldr r1, [r0]
	mov sb, r0
	ldrb r1, [r1, #8]
	cmp r3, r1
	bhs _0824C0B0
_0824C026:
	mov r0, sb
	ldr r2, [r0]
	lsls r1, r3, #5
	adds r0, r2, r1
	ldrh r0, [r0, #0x18]
	adds r4, r1, #0
	cmp r0, r8
	beq _0824C03E
	cmp r0, r6
	beq _0824C03E
	cmp r0, ip
	bne _0824C0A4
_0824C03E:
	adds r0, r3, #0
	mov r1, sp
	bl FUN_0824c0c4
	ldr r0, _0824C05C @ =gRfuLinkStatus
	ldr r0, [r0]
	adds r1, r0, r4
	ldrb r0, [r1, #0x16]
	cmp r0, #0xff
	bne _0824C060
	ldrh r0, [r1, #0x14]
	strh r0, [r5]
	movs r6, #3
	rsbs r6, r6, #0
	b _0824C068
	.align 2, 0
_0824C05C: .4byte gRfuLinkStatus
_0824C060:
	ldrh r0, [r1, #0x14]
	strh r0, [r5]
	movs r6, #4
	rsbs r6, r6, #0
_0824C068:
	movs r5, #0
_0824C06A:
	mov r0, sp
	adds r4, r0, r5
	adds r0, r4, #0
	bl FUN_0824c128
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r7, r0
	beq _0824C014
	adds r4, #1
	adds r0, r4, #0
	bl FUN_0824c120
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #7
	beq _0824C09E
	adds r0, r4, #0
	bl FUN_0824c120
	adds r1, r5, #2
	adds r0, r0, r1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0xf
	bls _0824C06A
_0824C09E:
	movs r0, #2
	rsbs r0, r0, #0
	b _0824C0B4
_0824C0A4:
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	ldrb r2, [r2, #8]
	cmp r3, r2
	blo _0824C026
_0824C0B0:
	movs r0, #1
	rsbs r0, r0, #0
_0824C0B4:
	add sp, #0x14
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
