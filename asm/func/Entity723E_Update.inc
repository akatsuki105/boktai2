	push {r4, r5, r6, lr}
	adds r5, r0, #0
	bl FUN_0804e59c
	cmp r0, #0
	beq _08052948
	ldr r0, _08052944 @ =0x000008B8
	adds r6, r5, r0
	movs r4, #3
_0805292E:
	ldm r6!, {r0}
	bl TextPanel_Destroy
	subs r4, #1
	cmp r4, #0
	bge _0805292E
	adds r0, r5, #0
	bl KillEntity
	b _08052958
	.align 2, 0
_08052944: .4byte 0x000008B8
_08052948:
	ldr r0, _08052960 @ =0x085AB724
	ldrb r1, [r5, #0x1c]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r5, #0
	bl _call_via_r1
_08052958:
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08052960: .4byte 0x085AB724
