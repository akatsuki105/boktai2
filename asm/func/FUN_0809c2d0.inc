	push {r4, lr}
	ldr r4, _0809C30C @ =0x0300013C
	ldr r1, [r4]
	cmp r1, #0
	beq _0809C304
	movs r2, #0x9e
	lsls r2, r2, #4
	adds r0, r1, r2
	ldr r0, [r0]
	cmp r0, #0
	beq _0809C304
	adds r0, r1, #0
	bl FUN_0808d774
	ldr r0, [r4]
	bl FUN_0808d564
	ldr r1, [r4]
	ldr r2, _0809C310 @ =0x000009FE
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #2
	bhi _0809C304
	adds r0, r1, #0
	bl FUN_0808d3d4
_0809C304:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809C30C: .4byte 0x0300013C
_0809C310: .4byte 0x000009FE
