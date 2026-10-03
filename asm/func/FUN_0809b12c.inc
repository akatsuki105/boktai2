	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r1, _0809B170 @ =0x00001084
	movs r0, #0x40
	bl FUN_0808a458
	ldr r0, _0809B174 @ =0x000010A4
	adds r4, r5, r0
	ldrh r0, [r4]
	adds r0, #0xf
	strh r0, [r4]
	lsls r0, r0, #0x10
	cmp r0, #0
	blt _0809B154
	movs r0, #0
	strh r0, [r4]
	ldr r1, _0809B178 @ =FUN_0809b180
	adds r0, r5, #0
	bl FUN_0808a33c
_0809B154:
	adds r3, r4, #0
	ldr r0, _0809B17C @ =0x00001104
	adds r1, r5, r0
	movs r2, #8
_0809B15C:
	ldrh r0, [r3]
	strh r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _0809B15C
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809B170: .4byte 0x00001084
_0809B174: .4byte 0x000010A4
_0809B178: .4byte FUN_0809b180
_0809B17C: .4byte 0x00001104
