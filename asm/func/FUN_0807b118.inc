	push {lr}
	ldr r0, _0807B12C @ =0x03002BE0
	ldr r0, [r0]
	cmp r0, #0
	beq _0807B128
	ldr r0, [r0, #0x1c]
	cmp r0, #4
	beq _0807B130
_0807B128:
	movs r0, #0
	b _0807B132
	.align 2, 0
_0807B12C: .4byte 0x03002BE0
_0807B130:
	movs r0, #1
_0807B132:
	pop {r1}
	bx r1
	.align 2, 0
