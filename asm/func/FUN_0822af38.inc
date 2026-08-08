	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	ldr r0, _0822AFB8 @ =0x03002CF0
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	ldr r1, _0822AFBC @ =0x00000401
	mov sb, r1
	cmp r0, #0
	beq _0822AF58
	ldr r2, _0822AFC0 @ =0x00000201
	mov sb, r2
_0822AF58:
	ldr r1, _0822AFC4 @ =0x03003560
	ldr r0, _0822AFC8 @ =0x03003530
	ldr r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r4, [r0]
	cmp r4, #0
	bne _0822AF6A
	b _0822B08A
_0822AF6A:
	ldr r3, _0822AFCC @ =0x030047C8
	mov r8, r3
_0822AF6E:
	ldr r1, [r4]
	adds r0, r1, #0
	mov r6, sb
	ands r0, r6
	cmp r0, #0
	beq _0822AF7C
	b _0822B082
_0822AF7C:
	movs r0, #0x80
	lsls r0, r0, #6
	ands r0, r1
	cmp r0, #0
	bne _0822AF88
	b _0822B082
_0822AF88:
	ldr r7, [r4, #0xc]
	mov ip, r7
	movs r0, #0x10
	ands r1, r0
	cmp r1, #0
	bne _0822B038
	mov r5, sp
	adds r6, r4, #0
	adds r6, #0x1c
	ldrh r0, [r4, #0x1c]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0822AFD0
	asrs r0, r0, #8
	b _0822AFD6
	.align 2, 0
_0822AFB8: .4byte 0x03002CF0
_0822AFBC: .4byte 0x00000401
_0822AFC0: .4byte 0x00000201
_0822AFC4: .4byte 0x03003560
_0822AFC8: .4byte 0x03003530
_0822AFCC: .4byte 0x030047C8
_0822AFD0:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0822AFD6:
	strh r0, [r5]
	adds r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0822AFE8
	asrs r0, r0, #8
	b _0822AFEE
_0822AFE8:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0822AFEE:
	adds r3, r0, #0
	movs r0, #2
	ldrsh r1, [r6, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _0822B002
	asrs r0, r0, #8
	b _0822B008
_0822B002:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0822B008:
	subs r2, r3, r0
	adds r3, r3, r0
	ldrh r0, [r5]
	mov r6, r8
	ldrh r1, [r6]
	subs r0, r0, r1
	adds r0, #0x78
	strh r0, [r5]
	ldrh r0, [r6, #2]
	subs r2, r2, r0
	adds r2, #0x5a
	strh r2, [r5, #2]
	ldrh r0, [r6, #4]
	subs r3, r3, r0
	strh r3, [r5, #4]
	mov r0, sp
	movs r7, #0
	ldrsh r6, [r0, r7]
	movs r1, #2
	ldrsh r5, [r0, r1]
	movs r3, #4
	ldrsh r2, [r0, r3]
	mov sl, r2
	b _0822B046
_0822B038:
	movs r7, #0x1c
	ldrsh r6, [r4, r7]
	movs r0, #0x1e
	ldrsh r5, [r4, r0]
	movs r2, #0x20
	ldrsh r1, [r4, r2]
	mov sl, r1
_0822B046:
	ldr r0, [r4]
	movs r1, #0x40
	ands r0, r1
	cmp r0, #0
	bne _0822B076
	mov r3, ip
	movs r0, #0xa
	ldrsb r0, [r3, r0]
	subs r1, r6, r0
	movs r0, #0xb
	ldrsb r0, [r3, r0]
	subs r2, r5, r0
	ldrb r0, [r3, #8]
	ldrb r3, [r3, #9]
	cmp r1, #0xf0
	bgt _0822B082
	cmp r2, #0xb4
	bgt _0822B082
	adds r0, r1, r0
	cmp r0, #0
	blt _0822B082
	adds r0, r2, r3
	cmp r0, #0
	blt _0822B082
_0822B076:
	adds r0, r4, #0
	adds r1, r6, #0
	adds r2, r5, #0
	mov r3, sl
	bl FUN_0822a574
_0822B082:
	ldr r4, [r4, #0x28]
	cmp r4, #0
	beq _0822B08A
	b _0822AF6E
_0822B08A:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
