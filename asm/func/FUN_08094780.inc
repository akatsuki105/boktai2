	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0808b8a4
	adds r0, r4, #0
	bl FUN_0809223c
	ldr r1, _080947C0 @ =0x00003F9C
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080947E0
	ldr r0, _080947C4 @ =0x00001BCC
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _080947C8 @ =0x00003AE8
	adds r0, r4, r1
	ldrb r1, [r0]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080947D4
	ldr r1, _080947CC @ =0x00001BC4
	adds r0, r4, r1
	ldr r1, _080947D0 @ =0x000002DF
	bl MainSprite_SetPltt
	b _080947E0
	.align 2, 0
_080947C0: .4byte 0x00003F9C
_080947C4: .4byte 0x00001BCC
_080947C8: .4byte 0x00003AE8
_080947CC: .4byte 0x00001BC4
_080947D0: .4byte 0x000002DF
_080947D4:
	ldr r1, _08094808 @ =0x00001BC4
	adds r0, r4, r1
	movs r1, #0xb8
	lsls r1, r1, #2
	bl MainSprite_SetPltt
_080947E0:
	ldr r0, _0809480C @ =0x00001C8C
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _08094810 @ =0x00003AE8
	adds r0, r4, r1
	ldrb r1, [r0]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0809481C
	ldr r1, _08094814 @ =0x00001C84
	adds r0, r4, r1
	ldr r1, _08094818 @ =0x000002DF
	bl MainSprite_SetPltt
	b _08094828
	.align 2, 0
_08094808: .4byte 0x00001BC4
_0809480C: .4byte 0x00001C8C
_08094810: .4byte 0x00003AE8
_08094814: .4byte 0x00001C84
_08094818: .4byte 0x000002DF
_0809481C:
	ldr r1, _08094834 @ =0x00001C84
	adds r0, r4, r1
	movs r1, #0xb8
	lsls r1, r1, #2
	bl MainSprite_SetPltt
_08094828:
	adds r0, r4, #0
	bl FUN_0808bac4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08094834: .4byte 0x00001C84
