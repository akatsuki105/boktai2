	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r6, #0
	adds r4, #0x70
	movs r5, #0x14
_0805296E:
	adds r0, r4, #0
	bl MainSprite_Remove
	subs r5, #1
	adds r4, #0x60
	cmp r5, #0
	bge _0805296E
	movs r0, #0x85
	lsls r0, r0, #4
	adds r4, r6, r0
	adds r0, r4, #0
	bl MainSprite_Remove
	ldr r0, _080529A8 @ =0x000008B8
	adds r4, r6, r0
	movs r5, #3
_0805298E:
	ldm r4!, {r0}
	bl TextPanel_Destroy
	subs r5, #1
	cmp r5, #0
	bge _0805298E
	ldr r1, _080529AC @ =0x0300011C
	movs r0, #0
	str r0, [r1]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080529A8: .4byte 0x000008B8
_080529AC: .4byte 0x0300011C
