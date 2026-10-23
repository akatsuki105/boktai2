	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080A40E4 @ =0x030046A0
	ldr r3, [r0]
	movs r0, #0x30
	ldrsh r1, [r3, r0]
	adds r0, r4, #0
	adds r0, #0x64
	movs r2, #0
	ldrsh r0, [r0, r2]
	subs r2, r1, r0
	cmp r2, #0
	bge _080A40B0
	rsbs r2, r2, #0
_080A40B0:
	movs r1, #0x34
	ldrsh r0, [r3, r1]
	adds r1, r4, #0
	adds r1, #0x68
	movs r3, #0
	ldrsh r1, [r1, r3]
	subs r1, r0, r1
	cmp r1, #0
	bge _080A40C4
	rsbs r1, r1, #0
_080A40C4:
	cmp r2, #0x60
	bgt _080A40E8
	cmp r1, #0x60
	bgt _080A40E8
	adds r0, r2, #0
	muls r0, r2, r0
	adds r2, r1, #0
	muls r2, r1, r2
	adds r1, r2, #0
	adds r0, r0, r1
	movs r1, #0x90
	lsls r1, r1, #6
	cmp r0, r1
	bgt _080A40E8
	movs r0, #1
	b _080A40EA
	.align 2, 0
_080A40E4: .4byte 0x030046A0
_080A40E8:
	movs r0, #0
_080A40EA:
	pop {r4}
	pop {r1}
	bx r1
