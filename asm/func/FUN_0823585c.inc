	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	adds r4, r3, #0
	ldr r3, [sp, #0x10]
	movs r0, #1
	rsbs r0, r0, #0
	adds r1, r3, #0
	muls r1, r3, r1
	adds r3, r1, #0
	cmp r2, #5
	bhi _082358E2
	lsls r0, r2, #2
	ldr r1, _08235880 @ =_08235884
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08235880: .4byte _08235884
_08235884: @ jump table
	.4byte _0823589C @ case 0
	.4byte _082358A6 @ case 1
	.4byte _082358B2 @ case 2
	.4byte _082358BE @ case 3
	.4byte _082358CA @ case 4
	.4byte _082358D6 @ case 5
_0823589C:
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08235090
	b _082358E2
_082358A6:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_08235178
	b _082358E2
_082358B2:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_082352c0
	b _082358E2
_082358BE:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_08235408
	b _082358E2
_082358CA:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_0823556c
	b _082358E2
_082358D6:
	adds r0, r5, #0
	ldr r1, [sp, #0x14]
	ldr r2, [sp, #0x18]
	adds r3, r4, #0
	bl FUN_082356c4
_082358E2:
	cmp r0, #0
	bge _082358EE
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08235090
_082358EE:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
