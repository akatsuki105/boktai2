	push {lr}
	lsls r1, r1, #2
	adds r0, #0x84
	adds r0, r0, r1
	ldr r1, [r0]
	lsrs r2, r1, #0x1f
	adds r0, r1, #0
	cmp r1, #0
	bge _0804971C
	rsbs r0, r1, #0
_0804971C:
	adds r1, r0, #0
	ldr r0, _08049728 @ =0x0098967F
	cmp r1, r0
	ble _0804972C
	adds r2, #8
	b _0804977E
	.align 2, 0
_08049728: .4byte 0x0098967F
_0804972C:
	ldr r0, _08049738 @ =0x000F423F
	cmp r1, r0
	ble _0804973C
	adds r2, #7
	b _0804977E
	.align 2, 0
_08049738: .4byte 0x000F423F
_0804973C:
	ldr r0, _08049748 @ =0x0001869F
	cmp r1, r0
	ble _0804974C
	adds r2, #6
	b _0804977E
	.align 2, 0
_08049748: .4byte 0x0001869F
_0804974C:
	ldr r0, _08049758 @ =0x0000270F
	cmp r1, r0
	ble _0804975C
	adds r2, #5
	b _0804977E
	.align 2, 0
_08049758: .4byte 0x0000270F
_0804975C:
	ldr r0, _08049768 @ =0x000003E7
	cmp r1, r0
	ble _0804976C
	adds r2, #4
	b _0804977E
	.align 2, 0
_08049768: .4byte 0x000003E7
_0804976C:
	cmp r1, #0x63
	ble _08049774
	adds r2, #3
	b _0804977E
_08049774:
	cmp r1, #9
	ble _0804977C
	adds r2, #2
	b _0804977E
_0804977C:
	adds r2, #1
_0804977E:
	adds r0, r2, #0
	pop {r1}
	bx r1
