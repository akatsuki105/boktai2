	push {lr}
	bl FUN_0807afe8
	ldr r1, _0807B304 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	adds r1, r0, #0
	cmp r1, #0
	beq _0807B30C
	ldr r2, _0807B308 @ =0x00000446
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _0807B30C
	subs r2, #4
	adds r0, r1, r2
	ldrh r0, [r0]
	b _0807B310
	.align 2, 0
_0807B304: .4byte 0x03002BE0
_0807B308: .4byte 0x00000446
_0807B30C:
	movs r0, #1
	rsbs r0, r0, #0
_0807B310:
	pop {r1}
	bx r1
