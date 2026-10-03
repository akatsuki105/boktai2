	push {lr}
	ldr r0, _0809C1DC @ =0x0300013C
	ldr r2, [r0]
	cmp r2, #0
	beq _0809C1D6
	ldr r1, _0809C1E0 @ =0x000009FE
	adds r0, r2, r1
	ldrb r1, [r0]
	ldr r3, _0809C1E4 @ =0x000009FF
	adds r0, r2, r3
	strb r1, [r0]
_0809C1D6:
	pop {r0}
	bx r0
	.align 2, 0
_0809C1DC: .4byte 0x0300013C
_0809C1E0: .4byte 0x000009FE
_0809C1E4: .4byte 0x000009FF
