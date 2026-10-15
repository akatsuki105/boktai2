	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080A3B5C @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x94
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrh r0, [r0]
	subs r0, #2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #2
	bls _080A3B64
	ldr r0, _080A3B60 @ =0x03002BE0
	ldr r3, [r0]
	movs r2, #0xe0
	lsls r2, r2, #2
	adds r0, r3, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _080A3B64
	movs r1, #0x2c
	ldrsh r0, [r3, r1]
	adds r1, r4, #0
	adds r1, #0xac
	movs r2, #0
	ldrsh r1, [r1, r2]
	subs r2, r0, r1
	cmp r2, #0
	bge _080A3B26
	rsbs r2, r2, #0
_080A3B26:
	movs r1, #0x30
	ldrsh r0, [r3, r1]
	adds r1, r4, #0
	adds r1, #0xb0
	movs r3, #0
	ldrsh r1, [r1, r3]
	subs r1, r0, r1
	cmp r1, #0
	bge _080A3B3A
	rsbs r1, r1, #0
_080A3B3A:
	cmp r2, #0x60
	bgt _080A3B64
	cmp r1, #0x60
	bgt _080A3B64
	adds r0, r2, #0
	muls r0, r2, r0
	adds r2, r1, #0
	muls r2, r1, r2
	adds r1, r2, #0
	adds r0, r0, r1
	movs r1, #0x90
	lsls r1, r1, #6
	cmp r0, r1
	bgt _080A3B64
	movs r0, #1
	b _080A3B66
	.align 2, 0
_080A3B5C: .4byte 0x030046A0
_080A3B60: .4byte 0x03002BE0
_080A3B64:
	movs r0, #0
_080A3B66:
	pop {r4}
	pop {r1}
	bx r1
