	push {lr}
	cmp r0, #1
	beq _0822CF08
	cmp r0, #1
	bgt _0822CEF4
	cmp r0, #0
	beq _0822CEFE
	b _0822CF20
_0822CEF4:
	cmp r0, #2
	beq _0822CF10
	cmp r0, #3
	beq _0822CF18
	b _0822CF20
_0822CEFE:
	ldr r0, _0822CF04 @ =0x04000010
	b _0822CF1A
	.align 2, 0
_0822CF04: .4byte 0x04000010
_0822CF08:
	ldr r0, _0822CF0C @ =0x04000014
	b _0822CF1A
	.align 2, 0
_0822CF0C: .4byte 0x04000014
_0822CF10:
	ldr r0, _0822CF14 @ =0x04000018
	b _0822CF1A
	.align 2, 0
_0822CF14: .4byte 0x04000018
_0822CF18:
	ldr r0, _0822CF24 @ =0x0400001C
_0822CF1A:
	strh r1, [r0]
	adds r0, #2
	strh r2, [r0]
_0822CF20:
	pop {r0}
	bx r0
	.align 2, 0
_0822CF24: .4byte 0x0400001C
