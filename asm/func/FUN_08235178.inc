	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r6, r0, #0
	mov sb, r1
	adds r0, r2, #0
	movs r1, #1
	rsbs r1, r1, #0
	mov sl, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl FUN_08234f44
	mov r8, r0
	cmp r0, #0
	beq _082351A4
	ldrb r0, [r0]
	cmp r0, #0
	bne _082351AE
_082351A4:
	movs r0, #0
	strh r0, [r6]
	strh r0, [r6, #2]
	strh r0, [r6, #4]
	b _082352AE
_082351AE:
	mov r0, r8
	bl FUN_08234f6c
	str r0, [sp, #0xc]
	cmp r0, #0
	bne _082351CE
	mov r7, sp
	ldrh r7, [r7, #0xc]
	strh r7, [r6]
	mov r0, sp
	ldrh r0, [r0, #0xc]
	strh r0, [r6, #2]
	mov r1, sp
	ldrh r1, [r1, #0xc]
	strh r1, [r6, #4]
	b _082352AE
_082351CE:
	mov r3, sl
	movs r5, #0
	mov r7, r8
	ldrb r7, [r7]
	cmp r5, r7
	bge _0823522A
	mov r4, sp
_082351DC:
	lsls r2, r5, #0x18
	lsrs r2, r2, #0x18
	mov r0, sp
	ldr r1, [sp, #0xc]
	str r3, [sp, #8]
	bl FUN_08234f80
	mov r0, sb
	movs r1, #0
	ldrsh r2, [r0, r1]
	movs r7, #0
	ldrsh r0, [r4, r7]
	subs r2, r2, r0
	mov r0, sb
	movs r7, #4
	ldrsh r1, [r0, r7]
	movs r7, #4
	ldrsh r0, [r4, r7]
	subs r1, r1, r0
	adds r0, r2, #0
	muls r0, r2, r0
	adds r2, r0, #0
	adds r0, r1, #0
	muls r0, r1, r0
	adds r2, r2, r0
	ldr r3, [sp, #8]
	cmp r2, r3
	bhs _08235220
	mov sl, r5
	adds r3, r2, #0
	ldrh r0, [r4]
	strh r0, [r6]
	ldrh r0, [r4, #4]
	strh r0, [r6, #4]
_08235220:
	adds r5, #1
	mov r1, r8
	ldrb r1, [r1]
	cmp r5, r1
	blt _082351DC
_0823522A:
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0823524E
	cmp r1, #0
	blt _0823524E
	ldr r0, _08235254 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0823524E
	ldr r0, _08235258 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0823525C
_0823524E:
	movs r4, #0
	b _0823526A
	.align 2, 0
_08235254: .4byte 0x030046A8
_08235258: .4byte 0x030046AC
_0823525C:
	ldr r0, _0823527C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0823526A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08235280
	adds r0, #4
	b _0823528C
	.align 2, 0
_0823527C: .4byte 0x030046A4
_08235280:
	ldr r0, _082352A0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0823528C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _082352A4
	cmp r2, #2
	beq _082352A8
	b _082352AC
	.align 2, 0
_082352A0: .4byte 0x030046A4
_082352A4:
	ldrb r0, [r6, #4]
	b _082352AA
_082352A8:
	ldrb r0, [r6]
_082352AA:
	subs r1, r1, r0
_082352AC:
	strh r1, [r6, #2]
_082352AE:
	mov r0, sl
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
