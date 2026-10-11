	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0xee
	ldrh r0, [r4]
	cmp r0, #0
	bne _0809F854
	ldr r0, _0809F868 @ =0x0000019F
	bl PlaySound_082406e0
_0809F854:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bhi _0809F86C
	movs r0, #3
	strh r0, [r5, #0x10]
	b _0809F884
	.align 2, 0
_0809F868: .4byte 0x0000019F
_0809F86C:
	cmp r0, #0xf
	bhi _0809F876
	movs r0, #4
	strh r0, [r5, #0x10]
	b _0809F884
_0809F876:
	movs r0, #5
	strh r0, [r5, #0x10]
	ldr r2, _0809F88C @ =FUN_0809f7fc
	adds r0, r5, #0
	movs r1, #1
	bl Entity1DBEElem_SetState
_0809F884:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809F88C: .4byte FUN_0809f7fc
