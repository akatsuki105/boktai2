	push {r4, r5, lr}
	ldr r5, _08247634 @ =0x04000208
	movs r2, #0
	strh r2, [r5]
	ldr r3, _08247638 @ =0x04000200
	ldrh r4, [r3]
	strh r2, [r3]
	ldr r0, _0824763C @ =0x0400010E
	strh r2, [r0]
	subs r0, #2
	strh r2, [r0]
	ldr r1, _08247640 @ =0x03002CB0
	ldr r0, _08247644 @ =IntrDummy
	str r0, [r1, #8]
	ldr r0, _08247648 @ =ROM_GPIOCNT
	strh r2, [r0]
	ldr r0, _0824764C @ =0x0000FFBF
	ands r0, r4
	strh r0, [r3]
	movs r0, #1
	strh r0, [r5]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08247634: .4byte 0x04000208
_08247638: .4byte 0x04000200
_0824763C: .4byte 0x0400010E
_08247640: .4byte 0x03002CB0
_08247644: .4byte IntrDummy
_08247648: .4byte ROM_GPIOCNT
_0824764C: .4byte 0x0000FFBF
