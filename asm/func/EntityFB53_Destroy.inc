	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0824172c
	ldr r0, [r4, #0x30]
	cmp r0, #0
	blt _0804B940
	bl TextPanel_Hide
	ldr r0, [r4, #0x30]
	bl TextPanel_Destroy
_0804B940:
	ldr r1, _0804B94C @ =0x030000D8
	movs r0, #0
	str r0, [r1]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0804B94C: .4byte 0x030000D8
