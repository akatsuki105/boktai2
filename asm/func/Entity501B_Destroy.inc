	push {r4, lr}
	adds r4, r0, #0
	bl Entity501B_HideTextPanels
	adds r0, r4, #0
	bl Entity501B_RemoveSprites
	adds r0, r4, #0
	bl Entity501B_RemoveAuxSprite
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1
