	push {lr}
	cmp r0, #2
	beq _0822CF38
	cmp r0, #2
	ble _0822CF48
	cmp r0, #3
	beq _0822CF40
	b _0822CF48
_0822CF38:
	ldr r0, _0822CF3C @ =0x04000018
	b _0822CF42
	.align 2, 0
_0822CF3C: .4byte 0x04000018
_0822CF40:
	ldr r0, _0822CF4C @ =0x0400001C
_0822CF42:
	strh r1, [r0]
	adds r0, #2
	strh r2, [r0]
_0822CF48:
	pop {r0}
	bx r0
	.align 2, 0
_0822CF4C: .4byte 0x0400001C
